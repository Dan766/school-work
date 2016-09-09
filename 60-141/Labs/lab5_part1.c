#include <stdio.h>
void FillArray(int *, int);	//This array will fill a given interger array with random numbers from 0-100
void PrintArray(int *, int); //This function will print a given interger array
void BubbleSort(int *, int); //This function will sort a given interger array in decending order
void Swap(int *, int *); //This function will swap two interger numbers 
int main (void)
{
	int NumList[20];
	int *array, size=20;
	array = NumList;
	printf("\n\tLab 5: More on Pointers");
	printf("\n\t=======================");
	printf("\nThis is a random array of 20 numbers from 0-100:");
	printf("\n\t");
	FillArray(array, size);
	PrintArray(array, size);
	printf("\nThis is the array sorted:");
	printf("\n\t");
	BubbleSort(array, size);
	PrintArray(array, size);
	return 0;
}
/*
	Objective: Thie objective of this function is to fill a given interger
		array of a given size with random interger numbers ranging from 1 to 100
	Input: Input is the address of the first value of an array, and the size of the array
		int *array
		int size
	Output: Output is a array of interger numbers with all its values filled with rand numbers
		int *array
*/
void FillArray(int *array, int size)
{
	int r;
	for (r=0;r<size;r++)
		*(array+r)=rand()%100+1;
	return;
}
/*
	Objective: Thie objective of this function is to print a given array of a given size of 
		interger values.
	Input: Input is the address of the first value of an array, and the size of the array
		int *array
		int size
	Output: Output is a array of interger numbers displayed to the user. 
		int *array
*/
void PrintArray(int *array, int size)
{
	int r;
	for (r=0;r<size;r++)
		printf("%d ", *(array+r));
	return;
}
/*
	Objective: Thie objective of this function is to sort a given array of interger numbers 
		in decending order 
	Input: Input is the address of the first value of an array, and the size of the array
		int *array
		int size
	Output: Output is a given array of interger numbers sorted in decending order
		int *array
*/
void BubbleSort(int *array, int size)
{
	int d,c;
	for (c=0;c<size-1;c++)
	{
		for (d=0; d< size-c-1; d++)
		{
			if (*(array+d)<*(array+d+1))
				Swap((array+d),(array+d+1));
		}
	}
}
/*
	Objective: Thie objective of this function is to swap two interger pointers with eachother
	Input: Input is two interger values
		int *A, *B;
	Output: Output is the two interger values swapped 
		int *A, *B;
*/
void Swap(int *A, int *B)
{
	int temp;
	temp = *A;
	*A = *B;
	*B = temp;
	return;
}