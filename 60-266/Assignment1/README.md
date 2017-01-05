Programming Exercise 1 (25 points):
==========
The greatest common divisor (GCD) of two integers is the largest integer that will evenly divide both integers. The GCD algorithm involves integer division in a loop, described by the following C/C++/Java code

    int GCD(int x, int y) 
    {
        x = abs(x);
        y = abs(y);
    do 
    {
        int n = x % y;
        x = y;
        y = n;
    }
    while y > 0;
        return y; 
    }

 Write the GCD function in ASM and write a piece of the main program code that calls this function with parameters x and y. GCD function should return a value in register EAX.

The greatest common divisor (GCD) of two integers X and Y is the largest integer Z that will evenly divide both integers. The GCD algorithm involves integer division in a loop; it is shown in the Question #1 of Final Exam 2005; see attachment.

Write the GCD function in ASM. Your main program must call this function with parameters X and Y. GCD function should return the  value Z in register EAX, and the main program should display this value Z. 

Programming Exercise 2 (25 points):
==========
Write the following recursive Greatest Common Divisor (GCD) program into ASM.

    public static long GCD(long a, long b)
    {
    If (b == 0)
        return a;
    Else
        return GCD(b, a % b); 
    }

Function GCD returns a value into EAX. Also, write a piece of the main program code that calls GCD. Assume that the Caller cleans the stack.

Programming Exercise 3 (25 points):
==========
Write an iterative (that is, a non-recursive) procedure for calculating the factorial of an integer number N. Also, you should write a MAIN procedure that calls the factorial procedure with parameter N, and display the result.

Programming Exercise 4 (25 points):
==========
Write a program that generates all prime numbers between 2 and 1000, using the Sieve of Eratosthenes method. You can find many articles that describe the method for finding primes in this manner on the Internet. Display all the prime values.
