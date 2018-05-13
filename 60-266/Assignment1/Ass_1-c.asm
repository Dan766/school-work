INCLUDE Irvine32.inc

.data
print1 BYTE "Here it is in LOWERCASE and in reverse order: ",13,10,0
input BYTE 128 dup(?)
counter BYTE ?

.code
main proc
	mov edx, OFFSET input
	mov ecx, 127
	call ReadString
	mov DWORD PTR counter, eax	; counter = # of chars
	mov ecx, eax	; counter is # of chars

	mov eax, edx
	mov edx, OFFSET print1
	call WriteString
	mov edx, eax		; temp stores current address

	;This loop changes each upper char to lower
	upper_to_lower:
		mov ah, [edx]
		cmp ah, 41h  ; cmp A
		jb less_A
			cmp ah, 5Ah  ; cmp Z
			ja greater_Z
				add ah, 20h
				mov [edx],ah
		greater_Z:
		less_A:
		inc edx ;next char
	loop upper_to_lower

	movzx ecx, counter ; loop counter is # of chars
	dec edx ;moves edx so it points to last char and not end of string (0)

	;This loop decrements edx and outputs each char (reverse order)
	print_reverse:
		mov al, [edx]
		call writechar
		dec edx			;next char
	loop print_reverse
	call crlf
	exit
main endp
end main