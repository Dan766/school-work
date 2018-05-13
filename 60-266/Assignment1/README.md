Programming Exercise 1 (30 points): [call it Ass_1-a.asm]
==========
Write an ASM program that will count the total number of characters, the number of lowercase characters, the numbers of decimal digits, and the number of blank characters contained in a text. You can implement anyone of the following alternatives.
You can read the input text from the keyboard. For example, if you read the following three-line text from the keyboard
 
     This is :
     A Sample Input,
     With Numbers 5 and 8.
Then your program Ass_1-a.exe should display the following 2 lines:
 
     This file contains 45 characters: out of which,
     26 are lowercase characters; 2 are decimal numbers; and, 8 are blank characters.
 
Programming Exercise 2 (30 points): [call it Ass_1-b.asm]
==========
Write an ASM program that reads an integer number N and then displays the first N values of the Fibonacci number sequence, described by:
Fib(0) = 0, Fib(1) = 1, Fib(N) = Fib(N-2) + Fib(N-1)
 
Thus, if the input is N = 10, your program Ass_1-b.exe should display the following single line:

    Fibonacci sequence with N = 10 is:  0   1   1   2   3   5   8   13   21   34   55

Programming Exercise 3 (40 points): [call it Ass_1-c.asm]
==========
Write an ASM program that prompts the user to enter a string of at most 128 characters and then displays the string in reverse order, with each upper-case letter converted to its corresponding lower-case letter. For instance, a sample execution of “Ass1-3.exe" with the input string “An InpuT Line!” is shown below

     C:\Programming\asm>Ass_1-c
     Enter a string of at most 128 characters:  An InpuT Line!
     Here it is in LOWERCASE and in reverse order:
     !enil tupni na
 
     C:\Programming\asm>
