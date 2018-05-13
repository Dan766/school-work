//By Daniel Fontana
#include <stdio.h>
//Function prototypes
int sum(int); //Sum function
int factorial(int); //Calculates the factorial
int fibonacci(int); //Calculates the fibonacci
int gcd(int, int); //Calculates the Greatest Common Divisor
int power(int, int); //Calculates the power                                      
int main(void)
{
	char choice;
	int n,n1,r,i,ans=0;
	while (choice != 'Q')
	{
		// Prints a selection menu onto the screen
		printf("\nChoose an option\n");
		printf("\tA. Sum\n"); 
		printf("\tB. Factorial\n");
		printf("\tC. Fibonacci\n");
		printf("\tD. gcd\n");
		printf("\tE. Power\n");
		printf("\tQ. Quit\n");
		scanf("%s",&choice);
		printf("\n");
		switch (choice)
		{
		//If the E option is chosen then the sum function will run
		case 'A':
			printf("\tSum\n\t====");
			printf("\nPlease enter a number: ");  
			scanf("%d", &n);
			printf("The sum is %d\n", sum(n));
			break;
		//If the E option is chosen then the factorial function will run
		case 'B':
			printf("\tFactorial\n\t==========");
			printf("\nPlease enter a number: ");  
			scanf("%d", &n);
			printf("The Factorial is %d\n", factorial(n));
			break;
		//If the E option is chosen then the fibonacci function will run
		case 'C':
			printf("\tFibonacci\n\t==========");
			printf("\nPlease enter the # of terms for the Fibonacci series: "); 
			scanf("%d", &n);
			i=0;
			
			for(r=0;r<n;r++)
			{
				ans+=fibonacci(i);
				i++;
			}
			printf("The Fibonacci is %d\n", ans);
			
			break;
		//If the E option is chosen then the gcd function will run
		case 'D':
			printf("\tGCD\n\t===");
			printf("\nPlease enter two numbers: ");
			scanf("%d %d", &n, &n1);
			printf("\nThe gcd is %d\n", gcd(n,n1)); 
			break;
		//If the E option is chosen then the power function will run
		case 'E':
			printf("\tPower\n\t=====");
			printf("\nPlease enter a number and its power: ");
			scanf("%d %d", &n, &n1);
			printf("The power is %d\n", power(n,n1));
			break;
		//If Q is entered the user is told to have a nice day and the while-loop exits + Program ends
		case 'Q':
			printf("\nHave a nice day!\n");
			break;
		//If non of the above values are entered than an prompt appears telling user the char is invalid
		default:	
			printf("INVALID OPTION!");
			break;
		}
	}
	return 0;
}
/*
	Objective: This function is used to calculate the 'sum' of 
		a number. The 'sum' being the sum of the series of 			
		numbers between 0 and the number entered.
	Input: Input is a single interger
		int n;
	Output: Output is a single interger representing the sum
		of the series from 0..n
		return (n+sum(n-1));
*/
int sum(int n)
{
	if (n==1)
		return (1);
	else
		return (n+sum(n-1));
}
/*
	Objective: This function is used to calculate the 'factorial'
		of a entered number. This will multiply all the int numbers
		of the series from 0 to the entered number.
	Input: The input is a single interger
		int n;
	Output: The output is a interger which is the multiplication of all
		members of the series 0..n
		return (n*factorial(n-1));
*/
int factorial(int n)
{
	if (n==1)
		return (1);
	else
		return (n*factorial(n-1));
	
}
/*
	Objective: The objective is to find the Fibonacci series of a
		particular number. This is done by adding up the two 
		numbers before each number.
	Input: The input is a single interger number 
		int n;
	Output: The output is the sum of the fibonacci series up to input num
		return (fibonacci(n-1) + fibonacci(n-2));
*/
int fibonacci(int n)
{
	if (n==0)
		return (0);
	else if (n==1)
		return (1);
	else 
		return (fibonacci(n-1) + fibonacci(n-2));
}
/*
	Objective: The objective of this function is to find the Greatest
		Common Divisor of two entered numbers. The GCD is the 
		largest number that can be divided into the two intergers
	Input: The input is two interger values 
	  	int n1, n2;
	Output: The output is a single interger value which is the largest
		number which can be divided into both functions
		return(gcd(n2, n1%n2));
*/
int gcd(int n1, int n2)
{
	if (n2 == 0)
		return(n1);
	else 
		return(gcd(n2, n1%n2));
}
/*
	Objective: This function is used to evaluate the value to a number 
		raised to the power of another number.
	Input: The input consists of two interger values
		int n1,n2;
	Output: The output consists of a single interger value which is equivalent
		to the second number raised to the first -> first^second <-
		return (n1*power(n1,n2-1));
*/
int power(int n1, int n2)
{
	if (n2 == 0)
		return (1);
	else
		return (n1*power(n1,n2-1));
}


