#pragma comment(lib, "detours.lib")

#include <memory>
#include <detours.h>
#include <iostream>

using namespace std;

void startProcessInject(char* exePath, char* dllPath) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	si.cb = sizeof(STARTUPINFO);
	DetourCreateProcessWithDll(NULL, exePath, NULL, NULL, FALSE, CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &si, &pi, dllPath, NULL);
}

int main(int argc, char** argv) {
	if (argc > 1) {
		unique_ptr<char> DirPath(new char[MAX_PATH]);
		unique_ptr<char> DetourPath(new char[MAX_PATH]);
		GetCurrentDirectory(MAX_PATH, DirPath.get());
		sprintf_s(DetourPath.get(), MAX_PATH, "%s\\HP1SpeedTools.dll", DirPath.get());
		startProcessInject(argv[1], DetourPath.get());
	}
	else {
		cout << "please specify the path to the HP1.exe as argument (for now, will make dynamic later)";
	}
	return 0;
}