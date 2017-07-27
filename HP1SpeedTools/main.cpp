#pragma comment(lib, "detours.lib")

#include <Windows.h>
#include <detours.h>
#include <thread>

class FPlane {
public:
	float x, y, z, w;
};

class _USoftwareRenderDevice {
public:
	int __thiscall Exec(unsigned short const * something, void* outputDevice)
	{
		return 0;
	}

	virtual void __thiscall Lock(FPlane x, FPlane y, FPlane z, unsigned long a, unsigned char *b, int *c) {
		MessageBox(0, "yaaay lock called", "o boi", 0);
	}
};

typedef int(__thiscall _USoftwareRenderDevice::*execFuncPtr_t)(unsigned short const* something, void* outputDevice);
struct pointerHolder {
	execFuncPtr_t fp;
};

//pointer to detour function
PVOID detourFP;

HMODULE hDLL;

DWORD WINAPI attachWaiter(LPVOID param) {
	//wait till SoftDrv.dll is loaded

	while (true) {
		std::chrono::milliseconds delay(1000);
		std::this_thread::sleep_for(delay);

		HMODULE moduleHandle = GetModuleHandle("SoftDrv.dll");
		if (moduleHandle != NULL) {

			FARPROC originalFP = GetProcAddress(moduleHandle, "?Lock@USoftwareRenderDevice@@UAEXVFPlane@@00KPAEPAH@Z"); //will it work? *drumroll* no clue yet lol
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());
			DetourAttach(&(PVOID&)originalFP, detourFP);
			if (DetourTransactionCommit() == NO_ERROR) {
				OutputDebugString("send() detoured successfully");
			}
			break;
		}
	}
	return 0;
}


void attach() {
	DisableThreadLibraryCalls(hDLL); //to prevent deadlock (i think, but cant hurt)
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
	ph.fp = &_USoftwareRenderDevice::Exec;
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