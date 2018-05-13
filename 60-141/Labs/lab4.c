#include <stdio.h>
//Function to swap int values
void Swap(int *, int *);
//Function to find the largest element in a list
int *Largest(int *, int);
int main (void)
{
	int x, y;
	int size=5;
	int array[5]={-29,-5,-1,0,-10};
	int r, *a;
	a = &array[0];
	//Prints the information for the swap function
	printf("\nSwap:\n");
	printf("\tInput two nums ");
	//Takes input for the swap funtion 
	scanf("%d %d", &x, &y);
	printf("\n\tBefore swap, x=%d and y=%d",x,y);
	Swap (&x, &y);
	printf("\n\tAfter swap, x=%d and y=%d\n",x,y);
	printf("\nLargest:\n");
	printf("\tThe list is: ");
	//prints the list
	for(r=0;r<size;r++)
		printf("%d ",*(array+r));
	//Prints the largest element of array
	printf("\n\tThe largest element in the list is %d\n\n", *Largest(a,size));
}
/*
	Objective: The objective of this function is to find the largest number of a
			given array given only that array and its size. It will return the 
			memory location of the largest num. 
	Input: the only input in this function is the interger array of a given size
			as well as the int size of the array
		int array[]
			-> used for holding a given list of interger values
		int size
			-> used for holding the number representing the size of the given array
	Output: The output of this function is a variable loaction called "largest" this
			is the largest element in the list 
*/
int *Largest(int *array, int size)
{
	int r=0;
	int *largest;
	largest = (array+r);
	for(r=0;r<size;r++)
	{
		if (*(array+r)>*largest)
			*largest = *(array+r);
	}
	return largest;
}
/*
	Objective: The Objective of this function is to Swap any two given interger 
			with eachother. It will assign the mem location of x to y and vice versa
	Input: The only input of this function is two integer values which are being swapped
		int *x
			-> the first int value
		int *y
			-> second int value
	Output: The output is the same as the input it returns the swapped versionsof the vars
*/
void Swap(int *x, int *y)
{
	//Temp variable
	int temp;
	temp = *x;
	*x = *y;
	*y = temp; 
}
