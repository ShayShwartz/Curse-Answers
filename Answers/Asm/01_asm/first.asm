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
	mov eax, 0
	mov ecx ,100
	
f0r:
	add eax, ecx
	loop f0r
	mov x, eax
	
end_program:
	mov eax, 0
	push eax
	call ExitProcess

end _start