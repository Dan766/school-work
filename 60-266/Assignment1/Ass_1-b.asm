INCLUDE Irvine32.inc

.data
print2 BYTE " is: ",0
print_space BYTE " ",0
print1 BYTE "Fibonacci seqence with N = ", 0
intNum BYTE ?
.code
main proc
	call ReadDec
	mov DWORD PTR intNum, eax
	movzx ecx, intNum ;loop counter is inputted number

	mov edx, OFFSET print1
	call WRITESTRING		; writes inital sentence
	call WRITEDEC			; outputs N
	mov edx, OFFSET print2	
	call WRITESTRING

	mov eax, 0	; a=0
	mov ebx, 1	; a=1
	call WRITEDEC		; outputs 0
	fib1:
		mov edx, eax
		add edx, ebx
		mov eax, ebx	; Number of concern
		mov ebx, edx
	
		mov edx, OFFSET print_space 
		call WRITESTRING			; Outputs a space
		call WRITEDEC				; Outputs each number of the sequence
	loop fib1
	call crlf

	exit
main endp
end main