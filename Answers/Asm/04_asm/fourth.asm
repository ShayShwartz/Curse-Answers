.486
.model flat, stdcall
option casemap :none

include \masm32\include\kernel32.inc
includelib \masm32\lib\kernel32.lib
include \masm32\include\masm32.inc
includelib \masm32\lib\masm32.lib

.data

.code
_start:
	mov ecx, 020h
	xor ebx, ebx
	
countTurnedOnBits:
	SHR ecx, 01h
	jc bitOn
	jnz countTurnedOnBits
	jmp checkNumberOfTurnedOnBits
	
bitOn:
	inc ebx
	jmp countTurnedOnBits

checkNumberOfTurnedOnBits:
	cmp ebx, 01h
	jz isAnExponentiation
	mov eax, 0FFFFFFFFh
	jmp end_program
	
isAnExponentiation:
	mov eax, 0

end_program:
	mov eax, 0
	push eax
	call ExitProcess

end _start