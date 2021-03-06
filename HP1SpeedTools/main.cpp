#pragma comment(lib, "detours.lib")

#include <Windows.h>
#include <detours.h>
#include <thread>
#include <chrono>

#include "Util.h"
#include "Hook.h"

using namespace std;

Hook lockHook;

class FPlane {
public:
	float x, y, z, w;
};

class _USoftwareRenderDevice;

typedef void(__thiscall _USoftwareRenderDevice::*lockFuncPtr_t)(FPlane x, FPlane y, FPlane z, unsigned long a, unsigned char *b, int *c);
struct pointerHolder {
	lockFuncPtr_t fp;
};

pointerHolder originalPointerHolder;
//pointer to detour function
PVOID detourFP;
PVOID originalFP;

HMODULE hDLL;


chrono::time_point<chrono::steady_clock> lastLock;
chrono::nanoseconds frameTime(1000000000 / 120);
int cnt = 0;
double actualFrameTime = -1;

class _USoftwareRenderDevice {
public:
	int __thiscall Exec(unsigned short const * something, void* outputDevice)
	{
		return 0;
	}

	DLLExport void __thiscall Lock(FPlane x, FPlane y, FPlane z, unsigned long a, unsigned char *b, int *c) {
		auto now = chrono::high_resolution_clock::now();
		auto diff = now - lastLock;
		auto toWait = frameTime - diff;
		if (toWait.count() > 0) {
			this_thread::sleep_for(toWait);
		}

		now = chrono::high_resolution_clock::now();
		diff = now - lastLock;

		lastLock = std::chrono::high_resolution_clock::now();

		if (actualFrameTime < 0) {
			actualFrameTime = 1000000000.0 / diff.count();
		}
		else {
			actualFrameTime = 0.9*actualFrameTime + 0.1*(1000000000 / diff.count());
		}

		cnt++;
		if (cnt > 1000) {
			cnt = 0;
			MessageBox(0, dblToString(actualFrameTime).c_str(), "frametime", 0);
		}
        
        //TODO: getting trampoline to work properly
		//jumpToCodeLocation(lockHook.trampoline.codeLocation);
		//(this->*(originalPointerHolder.fp))(x, y, z, a, b, c);
	}
};


DWORD WINAPI attachWaiter(LPVOID param) {
	//wait till SoftDrv.dll is loaded

	while (true) {
		std::chrono::milliseconds delay(1000);
		std::this_thread::sleep_for(delay);

		HMODULE moduleHandle = GetModuleHandle("SoftDrv.dll");
		if (moduleHandle != NULL) {

			originalFP = GetProcAddress(moduleHandle, "?Lock@USoftwareRenderDevice@@UAEXVFPlane@@00KPAEPAH@Z"); //yeah that works

			lockHook.initialize((intptr_t)originalFP, 5, (intptr_t)detourFP);
			/**((intptr_t*)(&originalPointerHolder)) = (intptr_t)originalFP;
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());
			DetourAttach(&(PVOID&)originalFP, detourFP);
			if (DetourTransactionCommit() == NO_ERROR) {
				OutputDebugString("send() detoured successfully");
			}*/
			break;
		}
	}
	//MessageBox(0, "softdrv.dll loaded", "yay", 0);
	return 0;
}


void attach() {
	DisableThreadLibraryCalls(hDLL); //to prevent deadlock in dllmain when starting thread (i think, but cant hurt)
	CreateThread(NULL, 0, attachWaiter, NULL, 0, NULL);
}

void detach() {
	//lets just ignore that for now. we would have to sync with the attachWaiter thread, and i dont even intend on detaching this dll
	/*DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)origin_execFuncPtr, detourFP);
	DetourTransactionCommit();*/
}

void setDetourFP() {
	pointerHolder ph;
	ph.fp = &_USoftwareRenderDevice::Lock;
	detourFP = (PVOID)*((intptr_t*)&ph); //convert to intptr_t* and dereference that (to get fp as int)
}

INT APIENTRY DllMain(HMODULE hDLL, DWORD Reason, LPVOID Reserved)
{
	switch (Reason)
	{
	case DLL_PROCESS_ATTACH:
		setDetourFP();

		::hDLL = hDLL;
		attach();
		break;
	case DLL_PROCESS_DETACH:
		detach();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}