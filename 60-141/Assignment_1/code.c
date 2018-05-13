#include<stdio.h>
//function used to find the next prime using a given prime 
int find_next_prime(int,int,int[],int *);
//Used in find_next_prime function to check if a number is a prime
int is_prime(int);	
//Function used to factorize the inputed number using primes
int find_prime_count(int, int [], int []);
//Function used to print the results 
int print_results(int *, int, int [], int []);

//Main function used to control program logic
int main(void)
{
	//Initialises main program variables 
	int n;						//input variable
	int r,next=2, c=0; 			//processing variables
	int primes[40],prime_count[40]; //output variables
	primes[0]=2;				//sets the first prime
	
	scanf("%d", &n); //Reads the input file for first input
	
	//Loops the main program until 0 is entered 
	while(n!=0)
	{
		for (r=0;r<40;r++)			//initialises counters 
			prime_count[r] =0;
		//Finds the prime numbers
		find_next_prime(n,next,primes,&c);	
		//Runs numbers from 2..n through the prime counter
		for (r=2;r<=n;r++) 
			find_prime_count(r, primes, prime_count);
		//prints the results 
		print_results(&c,n,primes,prime_count);
		scanf("%d", &n); //Reads input file for next input
	}
	return 0; //function end
}
/*
	Objective: The Objective of the print_results function is
		to output (print) all necessary output data to the 
		console using proper formatting 
	Inputs: 
		c -> c is a interger value used to specify the size of
			the primes array. More specifically c is the number
			of primes <= the inputed number
		n -> n is a interger value which is the number inputed 
			by the user
		primes -> primes is a interger array used to hold all the
			primes <= the inputed number
		prime_count -> prime_count is an integer array used to count
			the number of times each prime number appears in the
			prime factorization of the inputed value
	Output: The output is a formatted list of primes and their 
			respective prime count's. 
*/
int print_results(int *c, int n, int primes[], int prime_count[])
{
	int r,c1=0;
	printf("%d!  =  ",n);
	for (r=0;r<*c;r++)//Prints until there are no more primes left
	{
		if (r<*c-1)
		{
			printf("(%d^%d)*",primes[r],prime_count[r]);
			//Causes the output to continue to the next line
			//once passing 5 units of ouput 
			if (c1>5)
			{
				/*Used to fix faulty formatting due to decreasing 
				sizes of multiplicity messing up spacing, it allows
				more units to fit on lower lines (b/c they take less space)
				*/
				c1=-1;	
				printf("\n\t");
			}
		}
		//The last unit of output will have no * sign in order to keep
		//with formatting rules
		else
			printf("(%d^%d)",primes[r],prime_count[r]);
		c1++; //Increases the unit count
	}
	printf("\n\n");
	return 0; //function end
}
/*
	Objective: The Objective of the find_next_prime function
		is to calculate the next prime number given a existing 
		prime. 
	Inputs: 
		c -> c is a interger value used to specify the size of
			the primes array. More specifically c is the number
			of primes <= the inputed number
		num -> num is a interger value which is the number inputed 
			by the user
		primes -> primes is a interger array used to hold all the
			primes <= the inputed number
		next -> next is an interger value which represents a 
			possible prime number. 
	Output: This function will output the prime numbers it finds
		in a int array called primes as well as an int value 
		representing the size of that array, called c
*/
int find_next_prime(int num,int next, int primes[],int *c)
{
	int r;
	*c=1;	//Instalizes the prime size counter
	while (next<=num) //Runs until nextprime > inputed number
	{
		if (next%2==0) //If the nextprime is even it isnt prime, so add 1
			next+=1;
		else //If the nextprime is odd add two - this way we skip the next even
			next += 2;
		/*If the nextprime is a prime and is less then the inputed number
		then it will be added to the primes array
		*/
		if ((is_prime(next))&&(next<=num))
		{
			primes[*c] = next;
			*c+=1;
			next+=1;
		}		
	}
	return 0; //function end
}
/*
	Objective: The Objective of the is_prime function is to
		check if a given number is factorable by any number
		aside from itself and 1. If it is then a false value
		is returned, meaning  the number is not prime. If it 
		isnt factorable, than it is prime and a true value
		is returned. 
	Inputs: 
		next -> next is an interger value which represents a 
			possible prime number. 
	Output: The output is either 0 (a booleon false) or 1 
		(a booleon true) If true is returned that mean
		the function found that next is a prime, false means
		that next is not a prime. 
*/
int is_prime(int next)
{
	int r;
	//Using number 2 thu 9, checks if the nextprime is divisable 
	for (r=2;r<10;r++) 
	{
		//If nextprime is divisable and not by itself, than a false value is returned
		if ((next%r == 0)&&(r!=next))
		{
			return 0;
		}
	}
	return 1; //Returns a true value if nextprime is found to be a prime
}
/*
	Objective: The Objective of the find_prime_count function
		is to find how many times each given prime number appears
		in the factorization of n.  
	Inputs: 
		num -> num is a interger value which is the number inputed 
			by the user
		primes -> primes is a interger array used to hold all the
			primes <= the inputed number
		prime_count -> prime_count is an integer array used to count
			the number of times each prime number appears in the
			prime factorization of the inputed value
	Output: This function will output an interger array called
		prime_count. This array represents the number of times each 
		prime appears in the factorization of n. 
*/
int find_prime_count(int n, int primes[], int prime_count[])
{
	int c1=0; 
    while(n!=0)
	{
		/*If n is not divisable by a given prime, increase 
		the primes array position by 1*/
        if(n%primes[c1]!=0)
			c1 += 1;
		/*if n is divisable by a given prime, n is assigned the
		division value, and the prime count for the given prime
		is increased */
        else 
		{
            n /= primes[c1];
            prime_count[c1] += 1;
            if(n==1) //If n was equal to the prime stop the loop
                break;
        }
    }
	return 0; //function end
}
