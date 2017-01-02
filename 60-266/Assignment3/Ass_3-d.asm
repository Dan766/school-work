INCLUDE Irvine32.inc

.data
	arraySize EQU 1000					
    nums DWORD arraySize dup(0)			    
.code

main proc    					
	;-----------------------------------------------------------
	;First we fill the array nums with the inital values to 1000
	;-----------------------------------------------------------
	mov ecx, arraySize
	fillArray:		
	push ecx	
		sub ecx, arraySize
		neg ecx		
		mov eax, ecx				
	   	add eax, 2					; First prime is at 2 so we start here
	   	mov [nums+4*ecx], eax		; move the value into the array
	pop ecx
	loop fillArray
	   	
	
	;-----------------------------------------------------------
	;Now we use the Sieve of Eratosthenes to set all non primes
	;equal to -1 and leave prime indexes as their given numbers
	;-----------------------------------------------------------
   	main_loop:							
		mov ebx, ecx				
		inc ebx						
	   	cmp [nums+4*ecx], -1				; If index is -1, we
	   	je skip								; can skip as this num is not prime

			inner_loop:			
				cmp [nums+4*ebx], -1		; Again...skip if -1
				je skip2					
					sub edx, edx				; set edx and eax to zero		
					sub eax, eax				
					mov eax, [nums+4*ebx]		; move inner index into eax
					div [nums+4*ecx]			; divide inner index element with outer loop element
					cmp edx, 0					; check if numbers are divizable
					jne nxt					
						mov [nums+4*ebx], -1	; If any a number is not divisable by another, that number is not prime... so we set to -1
					nxt:							
				skip2:
				inc ebx						; Increment inner index
			cmp ebx, arraySize			
			jb inner_loop					

	   	skip:					
		inc ecx						; Increment outer index
		cmp ecx, arraySize			
		jb main_loop			

   	
	;-----------------------------------------------------------
	;Here we print to the screen all array indexes where numbers
	;not equal to -1 are found, this means the element is prime
	;-----------------------------------------------------------
	mov ecx, arraySize
   	print:	
	push ecx			
		sub ecx, arraySize
		neg ecx
   		cmp [nums+4*ecx], -1		
   		je nope						
			push ecx				
   			mov eax, [nums+4*ecx]
			call writedec
			call crlf
   			inc ebx						
   			pop ecx						
		nope:
   		inc ecx						; Incrementing
	pop ecx
   	loop print

    ret

main endp

end main