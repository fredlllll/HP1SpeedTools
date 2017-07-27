#pragma comment(lib, "detours.lib")

#include <Windows.h>
#include <detours.h>

class _USoftwareRenderDevice {
public:
	int __thiscall Exec(unsigned short const * something, void* outputDevice)
	{
		return 0;
	}
};

typedef int (__thiscall _USoftwareRenderDevice::*execFuncPtr_t)(unsigned short const* something, void* outputDevice);
struct pointerHolder {
	execFuncPtr_t fp;
};


PVOID detour_execFuncPtr;
PVOID origin_execFuncPtr;

HMODULE hDLL;

void attach(){
	DisableThreadLibraryCalls(hDLL);
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID&)origin_execFuncPtr, detour_execFuncPtr);
	if (DetourTransactionCommit() == NO_ERROR) {
		OutputDebugString("send() detoured successfully");
	}
}

void detach() {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(&(PVOID&)origin_execFuncPtr, detour_execFuncPtr);
	DetourTransactionCommit();
}

void setOriginalFP() {
	origin_execFuncPtr = (PVOID)0x444;
}

void setDetourFP() {
	pointerHolder ph;
	ph.fp = &_USoftwareRenderDevice::Exec;
	detour_execFuncPtr = (PVOID)*((intptr_t*)&ph); //convert to intptr_t* and dereference that (to get fp as int)
}

INT APIENTRY DllMain(HMODULE hDLL, DWORD Reason, LPVOID Reserved)
{
	switch (Reason)
	{
	case DLL_PROCESS_ATTACH:
		setOriginalFP();
		setDetourFP();

		::hDLL = hDLL;
		attach();
		break;
	case DLL_PROCESS_DETACH:
		detach();
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}