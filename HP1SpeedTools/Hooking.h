#pragma once

#include <Windows.h>

intptr_t followJump(intptr_t ptr) {
	UINT8 *code = (UINT8*)ptr;

	switch (code[0]) {
	case 0xEB: // jmp +imm8
		ptr = ptr + 2 + code[1];
		break;
	case 0xE9: // jmp +imm32
		ptr = ptr + 5 + *(UNALIGNED INT32 *)&code[1];
		break;
	case 0xFF: // jmp []
		if (code[1] == 0x25) { // jmp [imm32]
			//TODO?
		}
		break;
	}
	return ptr;
}

intptr_t followJumps(intptr_t ptr, UINT8 depth = 10) {
	intptr_t original = ptr;

	for (int i = 0; i < depth; i++) {
		original = ptr;
		ptr = followJump(ptr);
		if (ptr == original) {
			break;
		}
	}
	return ptr;
}
