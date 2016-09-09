//By Daniel Fontana
#include <stdio.h>
//Function prototypes
int sum(void); //Used to find the sum of given number
int factorial(void); //Used to calculate the factorial of a number
int fibonacci(void); //Calculates the fibonacci of a number
int gcd(void); //Calculates the Greatest Common Divisor
int power(void); //Calcs the Power
int main(void) 
{
	char choice;
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
			sum();
			break;
		//If the E option is chosen then the factorial function will run
		case 'B':
			factorial();
			break;
		//If the E option is chosen then the fibonacci function will run
		case 'C':
			fibonacci();
			break;
		//If the E option is chosen then the gcd function will run
		case 'D':
			gcd();
			break;
		//If the E option is chosen then the power function will run
		case 'E':
			power();
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
		int ans;
*/
int sum(void)
{
	int i=0;
	int num,n,ans;
	printf("\tSum\n\t===");
	printf("\nPlease enter a number: "); 
	scanf("%d", &n);
	num = n;
	for (i=0; i<=num; i++)
	{
		n += i;
	}
	ans = n;
	printf("\nThe sum of %d is %d\n", num, ans);
	return(0);
}
/*
	Objective: This function is used to calculate the 'factorial'
		of a entered number. This will multiply all the numbers
		of the series from 0 to the entered number.
	Input: The input is a single interger
		int n;
	Output: The output is a interger which is the multiplication of all
		members of the series 0..n
		int ans;
*/
int factorial(void)
{
	int ans,num,r,n;
	printf("\tFactorial\n\t==========");
	printf("\nPlease enter a number: ");  
	scanf("%d", &n);
	num = n;
	if (n==0)
	{
		printf("The factorial of %d is 1\n", num);
	}
	else
	{
		for (r=n-1;r>1;r--)
		{
			n *= r;
		}
		ans = n;
		printf("The factorial of %d is %d\n", num, ans);
	}	
}
/*
	Objective: The objective is to find the Fibonacci series of a
			particular number. This is done by adding up the 
			two numbers before each number.
	Input: The input is a single interger number 
			int n;
	Output: The output is 
*/
int fibonacci(void)
{
	int n, b, first, second,next;
	first=0;
	second=1;
	printf("\tFibonacci\n\t==========");
	printf("\nPlease enter the # of terms for the Fibonacci series: "); 
	scanf("%d", &n);
	printf("First %d terms of the Fibonacci series are: \t \n", n);
	for (b=0;b<n;b++)
	{
		if (b<=1)
			next = b;
		else
		{
			next = first+second;
			first=second;
			second=next;
		}
		printf("%d\n", next);
	}
	
	
	
}
/*
	Objective: The objective of this function is to find the Greatest
		Common Divisor of two entered numbers. The GCD is the 
		largest number that can be divided into the two intergers
	Input: The input is two interger values 
	  	int n1, n2;
	Output: The output is a single interger value which is the largest
		number which can be divided into both functions
		int ans;
*/
int gcd(void)
{
	int r,n1,n2,num1,num2,ans;
	char end = 'F';
	printf("\tGCD\n\t===");
	printf("\nPlease enter two numbers: ");
	scanf("%d %d", &n1, &n2);
	num1 = n1;
	num2 = n2;
	while (end != 'T') 
	{
		
		if (n1 > n2)
		{
			n1 -= n2;
		}
		else if (n2 > n1)
		{
			n2 -= n1;
		} 		
		else
		{
			n1 = ans;
			printf("The GCD of %d and %d is %d\n", num1,num2,ans);
			end = 'T';
		}
	}
}
/*
	Objective: This function is used to evaluate the value to a number 
		raised to the power of another number.
	Input: The input consists of two interger values
		int n1,n2;
	Output: The output consists of a single interger value which is equivalent
		to the second number raised to the first -> first^second <-
		int ans;
*/
int power(void)
{
	int r,ans,n1,n2,num1,num2;
	printf("\tPower\n\t=====");
	printf("\nPlease enter a number and its power: ");
	scanf("%d %d", &n1, &n2);
	num1=n1;
	num2=n2;
	for (r=1;r<n2;r++)
	{
		n1*=num1;
	}
	ans = n1;
	printf("\nThe Power of %d ^ %d is equal to %d\n", num1,num2, ans);
}


