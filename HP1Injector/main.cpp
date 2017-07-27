#pragma comment(lib, "detours.lib")

#include <memory>
#include <detours.h>
#include <iostream>

using namespace std;

void startProcessAndInject(char* exePath, char* dllPath) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	si.cb = sizeof(STARTUPINFO);

	//either with detours
	DetourCreateProcessWithDll(NULL, exePath, NULL, NULL, FALSE, CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &si, &pi, dllPath, NULL);

	//or with createremotethread. both have the same result
	/*
	if (CreateProcess(NULL, exePath, NULL, NULL, FALSE, CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &si, &pi)) {
		LPVOID LoadLibraryAddr = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");
		LPVOID LoadLibraryParam = (LPVOID)VirtualAllocEx(pi.hProcess, NULL, strlen(dllPath), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE); //allocating memory in other process
		WriteProcessMemory(pi.hProcess, LoadLibraryParam, dllPath, strlen(dllPath), NULL); //writing dll path there
		CreateRemoteThread(pi.hProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryAddr, LoadLibraryParam, NULL, NULL); //calling load library using remote thread
		VirtualFreeEx(pi.hProcess, LoadLibraryParam, 0, MEM_RELEASE); //free memory after calling loadLibrary
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	*/
}

int main(int argc, char** argv) {
	if (argc > 1) {
		unique_ptr<char> DirPath(new char[MAX_PATH]);
		unique_ptr<char> DetourPath(new char[MAX_PATH]);
		GetCurrentDirectory(MAX_PATH, DirPath.get());
		sprintf_s(DetourPath.get(), MAX_PATH, "%s\\HP1SpeedTools.dll", DirPath.get());
		startProcessAndInject(argv[1], DetourPath.get());
	}
	else {
		cout << "please specify the path to the HP1.exe (with arguments) as argument (for now, will make dynamic later)";
	}
	return 0;
}