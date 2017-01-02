INCLUDE Irvine32.inc

.data
	promptInvalid BYTE "Invalid Input, enter a number between 0 and 65535: ",0
.code

DisplayHexByte PROC
;----------------------------------------------------
; Displays a given Byte sized int in hex form
; Recieves: BX, the given int to display
; Returns: The output to the display (int in hex form)
; Requires: BX = the number to be displayed
;----------------------------------------------------
	movzx eax, BX
	mov ebx, 1
	call WriteHexB 
	ret
DisplayHexByte ENDP

DisplayHexDigit PROC
;----------------------------------------------------
; Displays a given single Digit sized int in hex form
; Recieves: BX, the given int to display
; Returns: The output to the display (int in hex form)
; Requires: BX = the number to be displayed
;----------------------------------------------------
	mov al, bl
	;if <10 then it can be output as a digit
	cmp al, 10
	jae greater
		call WriteDec
	jmp end_t
	greater:
		;if >10 then it is a char (A,B,etc)
		add al, 37h
		call WriteChar 
	end_t:
	ret
DisplayHexDigit ENDP

DisplayHexWord PROC
;----------------------------------------------------
; Displays a given WORD sized int in hex form
; Recieves: BX, the given int to display
; Returns: The output to the display (int in hex form)
; Requires: BX = the number to be displayed
;----------------------------------------------------
	movzx eax, BX
	mov ebx, 2
	call WriteHexB 
	ret
DisplayHexWord ENDP

main proc
	;Reads a valid input from the keyboard
	read:
		call ReadInt
		jno goodInput

		badInput:
			mov edx, OFFSET promptInvalid
			call WriteString
			jmp read
	goodInput:
		cmp eax, 65535
		ja badInput
	;-------------------------------
	;Chooses a function based on the size of the input integer
	mov ebx, eax
	;number is less then 15 - call hex digit
	cmp bx, 0Fh
	ja next
		call DisplayHexDigit
		jmp end_prog
	next:
		;number is less then 255 - call hex BYTE
		cmp bx, 0FFh
		ja next2
			call DisplayHexByte
			jmp end_prog	
		next2:
			;number is 255+ - call hex WORD
			call DisplayHexWord
	end_prog:
	call crlf
	exit
main endp
end main
