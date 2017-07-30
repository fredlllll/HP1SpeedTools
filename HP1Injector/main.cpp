#include <memory>
#include <Windows.h>
#include <iostream>
#include <string>
#include <PathCch.h>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

shared_ptr<map<string, string>> readConfig(string &file) {
	ifstream infile(file);

	string line;
	shared_ptr<map<string, string>> config(new map<string, string>());
	while (getline(infile, line))
	{
		size_t firstEquals = line.find_first_of('=');
		string name = line.substr(0, firstEquals);
		string value = line.substr(firstEquals + 1);
		config->insert_or_assign(name, value);
	}
	return config;
}

void startProcessAndInject(string exePath, string args, string dllPath) {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	si.cb = sizeof(STARTUPINFO);

	size_t lastBackslash = exePath.find_last_of('\\');
	string workingDir = exePath.substr(0, lastBackslash);
	cout << "working dir:\n" << workingDir << "\n";


	string commandLine = "\"" + exePath + "\" " + args;

	if (CreateProcess(NULL, (LPSTR)commandLine.c_str(), NULL, NULL, FALSE, CREATE_DEFAULT_ERROR_MODE | CREATE_SUSPENDED, NULL, workingDir.c_str(), &si, &pi)) {
		LPVOID LoadLibraryAddr = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");
		cout << "LoadLibraryAddr: " << LoadLibraryAddr << "\n";
		LPVOID LoadLibraryParam = (LPVOID)VirtualAllocEx(pi.hProcess, NULL, dllPath.length() + 1, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE); //allocating memory in other process

		cout << "LoadLibraryParam: " << LoadLibraryParam << "\n";
		if (!WriteProcessMemory(pi.hProcess, LoadLibraryParam, dllPath.c_str(), dllPath.length() + 1, NULL)) { //writing dll path there
			cout << "error calling WriteProcessMemory\n";
		}
		DWORD threadId;
		HANDLE threadHandle = CreateRemoteThread(pi.hProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryAddr, LoadLibraryParam, NULL, &threadId); //calling load library using remote thread
		cout << "threadId: " << threadId << "\n";
		WaitForSingleObject(threadHandle, 5000);//wait 5 second at max
		CloseHandle(threadHandle);
		if (!VirtualFreeEx(pi.hProcess, LoadLibraryParam, 0, MEM_RELEASE)) { //free memory after calling loadLibrary
			cout << "error calling VirtualFreeEx\n";
		}

		ResumeThread(pi.hThread); //resuming main thread after injection is done

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}

int main(int argc, char** argv) {
	unique_ptr<char> executablePath(new char[MAX_PATH]);
	GetModuleFileName(NULL, executablePath.get(), MAX_PATH);

	string executableDir(executablePath.get());
	executableDir = executableDir.substr(0, executableDir.find_last_of('\\'));


	string configPath = executableDir + "\\config.ini";

	cout << "config: " << configPath << "\n";

	auto config = readConfig(configPath);

	string detourPath = executableDir + "\\HP1SpeedTools.dll";
	cout << "going to inject\n" << detourPath << "\ninto\n" << config->at("exe") << "\n";
	startProcessAndInject(config->at("exe"), config->at("parameters"), detourPath);
	return 0;
}