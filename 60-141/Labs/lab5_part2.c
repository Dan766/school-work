#include <stdio.h>
int main ()
{
	int a = 7 ;
	int *aPtr ;
	aPtr = &a ;
		//Assigns the pointer called aPtr to the address of the variable called a
	printf( "%p", &a );
		//prints the address location of the variable a
		//Output: Address of a
	printf( "%p", aPtr );
		//prints the aPtr which is the address of a
		//Output: Adress of a
	printf( "%p", &aPtr );
		//This will print the address location of the pointer variable aPtr
		//Output: address of aPtr
	printf( "%d", a );
		//This will print the value of variable a
		//output: 7
	printf( "%d", *aPtr );
		//This will print the value stored at the location pointed to by aPtr
		//Output: 7
	printf( "\n\n\n%p", *&aPtr );
		//prints the address location pointed to by the pointer aPtr (adress of a) 
		//Output: Address of a
	printf( "%p", &*aPtr );
		//This will print the address location of the value pointed to by the aPtr pointer
		//Output: Address of a
	printf( "%d", *&a );
		//This will print the value stored at the address location of a
		//Output: 7
	printf( "%d", &*a );
		//This will produce an ERROR
		// 	This code will try to dereference a value, which is not possible since
		//	dereferencing can only be used on address locations
	return 0;
}
