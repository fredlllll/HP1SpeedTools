#pragma once
#include <Windows.h>

class Trampoline
{
public:
	intptr_t codeLocation;

	Trampoline() :codeLocation(NULL) {}

	void initialize(intptr_t originalCodeLocation, size_t oldCodeSize)
	{
		codeLocation = (intptr_t)VirtualAlloc(NULL, oldCodeSize + 5, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
		memcpy((void*)codeLocation, (BYTE*)originalCodeLocation, oldCodeSize);

		BYTE JMPInstruction[5] = { 0xE9, 0x90, 0x90, 0x90, 0x90 };

		intptr_t jmpTarget = originalCodeLocation + oldCodeSize;
		intptr_t jmpOffset = jmpTarget - ((intptr_t)codeLocation + oldCodeSize + sizeof(JMPInstruction));

		*((INT32*)&JMPInstruction[1]) = jmpOffset;
		memcpy((void*)(codeLocation + oldCodeSize), JMPInstruction, sizeof(JMPInstruction));

		DWORD oldProtect;
		VirtualProtect((LPVOID)codeLocation, oldCodeSize + 5, PAGE_EXECUTE, &oldProtect);//protect code
	}

	~Trampoline()
	{
		if (codeLocation != NULL) {
			VirtualFree((void*)codeLocation, 0, MEM_RELEASE);
		}
	}


};

__forceinline void jumpToCodeLocation(intptr_t codeLocation) {
	__asm {
		push codeLocation
		retn
	}
}
