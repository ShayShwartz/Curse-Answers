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
	mov eax, 0AABBCCDDh
	
reverseBytes:
	SHL ebx, 8
	mov bl, al
	SHR eax, 8
	test eax, eax
	jnz reverseBytes
	

saveResult:
	mov eax, ebx

end_program:
	mov eax, 0
	push eax
	call ExitProcess

end _start