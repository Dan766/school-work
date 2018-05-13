INCLUDE Irvine32.inc

.data
char_count BYTE 0
lower_count BYTE 0
num_count BYTE 0
space_count BYTE 0

p1 BYTE "This file contains ", 0
p2 BYTE " characters of which, ", 13,10, 0
p3 BYTE " are lowercase characters; ",0
p4 BYTE " are decimal number; and, ",0
p5 BYTE " are blank characters.",13,10,0

input BYTE 128 dup(?)

.code
main proc
	;--------------------------
	; Main loop used for taking 
	; each line of input
	;--------------------------
	main_loop:
		mov edx, OFFSET input
		mov ecx, 127
		call ReadString
		add DWORD PTR char_count, eax
		mov ecx, eax ; set loop counter to # of chars
		;--------------------------
		; Inner loop used for each
		; char in each given line
		;--------------------------
		loop_main:
			mov ah, [edx]
			cmp ah, 20h
			jne not_space
				inc space_count ; If space ++counter
			not_space:			
			cmp ah, 30h  ; cmp 0
			jb less_0
				cmp ah, 39h  ; cmp 9
				ja greater_9
					inc num_count ; If number ++counter
			greater_9:
			less_0:
			cmp ah, 61h  ; cmp a
			jb less_a1
				cmp ah, 7Ah  ; cmp z
				ja greater_z1
					inc lower_count ; If lower ++counter
			greater_z1:
			less_a1:			
			inc edx ;next char
		loop loop_main
	cmp ah, 2Eh
	jne main_loop
	;--------------------------

	mov edx, OFFSET p1
	call writestring
	movzx eax, char_count
	call writedec

	mov edx, OFFSET p2
	call writestring
	mov al, lower_count
	call writedec

	mov edx, OFFSET p3
	call writestring
	mov al, num_count
	call writedec

	mov edx, OFFSET p4
	call writestring
	mov al, space_count
	call writedec

	mov edx, OFFSET p5
	call writestring
	exit
main ENDP
END main
