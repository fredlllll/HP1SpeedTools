#pragma once
#include <Windows.h>
#include "Hooking.h"
#include "Trampoline.h"

class Hook
{
public:

	Trampoline trampoline;

	Hook() {}

	~Hook()
	{
	}

	void initialize(intptr_t target, int stolenBytesCount, intptr_t replacement)
	{
		//follow jumps of the function pointers
		target = followJumps(target);
		replacement = followJumps(replacement);

		INT32 jmpOffset = replacement - (target + 5);

		//MessageBox(0, intToHex(jmpOffset).c_str(), "jmpoffset", 0);

		BYTE JMPInstruction[] = { 0xE9, 0x90, 0x90, 0x90, 0x90 }; // JMP 0x90909090
		*((INT32*)&JMPInstruction[1]) = jmpOffset; //writing offset into instruction
		DWORD oldProtect;
		VirtualProtect((LPVOID)target, sizeof(JMPInstruction), PAGE_EXECUTE_READWRITE, &oldProtect);//enable writing on location of target code

		//BYTE* oldCode = new BYTE[stolenBytesCount];
		//memcpy(oldCode, (void*)target, sizeof(oldCode));
		trampoline.initialize(target, stolenBytesCount);
		//delete[] oldCode;
		memcpy((void*)target, JMPInstruction, sizeof(JMPInstruction));

		VirtualProtect((LPVOID)target, sizeof(JMPInstruction), oldProtect, &oldProtect);//restore previous protection
	}
};

