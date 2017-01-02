INCLUDE Irvine32.inc

.data
	num1 DWORD ?
	num2 DWORD ?
	p1 BYTE "GCD of ",0
	p2 BYTE " and ",0
	p3 BYTE " is ",0

.code

gcd PROC USES ECX 
;----------------------------------------------------
; Displays a given Byte sized int in hex form
; Recieves: EAX and ECX
; Returns: EAX = the greatest common denominator
; Requires: EAX and ECX
;----------------------------------------------------
	LOOP_main:
		cmp ecx, 0
		jle Negative

		sub edx, edx
		div ecx 
		mov eax, ecx
		mov ecx, edx
	jmp LOOP_main
	Negative:
	ret
gcd ENDP

main proc
	
	mov num1, 1001d
	mov num2, 99d

	mov edx, OFFSET p1
	call WriteString
	mov eax, num1
	call writedec

	mov edx, OFFSET p2
	call WriteString
	mov eax, num2
	call writedec

	mov eax, num1
	mov ecx, num2
	call gcd

	mov edx, OFFSET p3
	call WriteString
	call writedec
	call crlf

	exit
main endp
end main
