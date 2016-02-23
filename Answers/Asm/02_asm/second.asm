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
	mov eax, 0Ch
	mov ebx, 04h
	mov ecx, 08h
	
firstCmp:
	cmp ebx, eax
	jg ebxBigger
	
secondCmp:
	cmp ecx,eax
	jg ecxBigger
	jmp end_program
	
ebxBigger:
	mov eax, ebx
	jmp secondCmp
	
ecxBigger:
	mov eax, ecx

end_program:
	mov eax, 0
	push eax
	call ExitProcess

end _start