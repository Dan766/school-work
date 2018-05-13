#include<stdio.h>
#define M 6
#define N 5
//Function that will print array
void PrintArray2D(int [M][N]);
//Function that will generate values for the 2D array
int PopulateRandom2D(int [M][N]); 
//Function that will find if an int value is in the array
int LinearSearch2D(int [M][N],int);
//Function that will shift all values of a 2D array to the left
int LeftShift2D(int [M][N]);
//Main function logic
int main(void)
{
	int A2D[M][N],key;
	char choice = 'Y';
	while (choice != 'Q')
	{
		// Prints a selection menu onto the screen
		printf("Choose an option\n");
		printf("\tA. PrintArray2D     \n");
		printf("\tB. PopulateRandom2D \n");
		printf("\tC. LinearSearch2D   \n");
		printf("\tD. LeftShift2D      \n");
		printf("\tQ. Quit\n");
		scanf("%s",&choice);
		printf("\n");
		switch (choice)
		{
		//If the E option is chosen then the PrintArray function will run
		case 'A':
			PrintArray2D(A2D);
			printf("\n\n");
			break;
		//If the E option is chosen then the Populate  function will run
		case 'B':
			PopulateRandom2D(A2D);
			PrintArray2D(A2D);
			break;
		//If the E option is chosen then the LinearSearch function will run
		case 'C':
			PopulateRandom2D(A2D);
			printf("Enter a key: ");
			scanf("%d",&key);
			if (LinearSearch2D(A2D,key))
				printf("\n%d is in the list\n\n",key);
			else
				printf("\n%d is not in the list\n\n",key);
			break;
		//If the E option is chosen then the LeftShift function will run
		case 'D':
			LeftShift2D(A2D);
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
	Objective: The objective of this function is to print a two dimensional
		array given the array and the size M by N
	Input: The input is a M by N array called A2D
		int A2D[M][N];
	Output: The output is the array 'A2D' printed in a table format
		int A2D[M][N];
*/
void PrintArray2D(int A2D[M][N])
{
	int r,c;
	//Prints the function
	printf("\nThe List:");
	for (r=0;r<M;r++)
	{
		printf("\n\t");
		for(c=0;c<N;c++)
			printf("%d ", A2D[r][c]);
	}
}
/*
	Objective: The objective of this function is to search any interger
		M by N two dimensional array given the array an a single interger
		search key. If the key is found anywhere in the 2D array, then
		True is returned, Flase otherwise.
	Input: The input is a M by N array called A2D as well as a int key
		int A2D[M][N];
		int key;
	Output: The output of this function is either a booleon True or False. 
		True will be returned if the search key is found, False otherwise
		return 1; return 0;
*/
int LinearSearch2D(int A2D[M][N],int key)
{
	int r,c;
	for (r=0;r<M;r++)
	{
		for(c=0;c<N;c++)
		{
			if (A2D[r][c] == key)//If we find the key, return True
				return 1;
		}
	}
	return 0; //End of function / Return False
	
}
/*
	Objective: The objective of this function is to generate random numbers from 1
		to M * N and place them in each value of the 2D interger array 'A2D'. 
	Input: The input is a M by N array called A2D
		int A2D[M][N];
	Output: The output of this function is an array called 'A2D' which is filled with
		random values from 1 to M * N. 
		int A2D[M][N];
*/
int PopulateRandom2D(int A2D[M][N])
{
	int r,c;
	for (r=0;r<M;r++)
	{
		for(c=0;c<N;c++)
		{
			A2D[r][c] = rand() %(M*N); //Generates a rand value from 1 to M*N and assigns to A2D[r][c]
			if (A2D[r][c] == 0) //If there is a 0 set it to 1, this removes the error 
				A2D[r][c] = 1;
		}
	}
	return 0; //End of function
	
}
/*
	Objective: The objective of this function is to shift each value of a 2D
		array to the left in location by 1 unit. 
	Input: The input is a M by N array called A2D
		int A2D[M][N];
	Output: The output is the array 'A2D' with all its original values shifted left 1
		int A2D[M][N];
*/
int LeftShift2D(int A2D[M][N])
{
	int r, c, temp;
	for (r=0;r<M;r++) //row loop
	{
		for (c=0;c<N;c++) //column loop
		{
			if (c==0) //When we are at the first column
			{
				if (r==0) //Sets temp = the first position of the array 
					temp = A2D[r][c];
				else //Shifts the first element in the rows to the end of the row above 
					A2D[r-1][N-1] = A2D[r][c];
			}
			else //Shifts each element of the list to the left
				A2D[r][c-1] = A2D[r][c];
		}
	}
	//Sets the original first value to the end of the new list 
	A2D[M-1][N-1] = temp;
}
