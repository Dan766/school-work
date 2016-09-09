#include <stdio.h>
int main()
{
	int num1, num2;
	int newnum1, newnum2;
	int digit1of1, digit2of1, digit3of1, digit4of1;
	int digit1of2, digit2of2, digit3of2, digit4of2;
	int sum;
	
	printf("\nInput the first number: ");
	scanf("%d", &num1);
	printf("Input the second number: ");
	scanf("%d", &num2);

	digit4of1 = num1%10;
	newnum1 = num1/10;
	digit3of1 = newnum1%10;
	newnum1 = newnum1/10;
	digit2of1 = newnum1%10;
	newnum1 = newnum1/10;
	digit1of1 = newnum1%10;
	newnum1 = newnum1/10;

	digit4of2 = num2%10;
	newnum2 = num2/10;
	digit3of2 = newnum2%10;
	newnum2 = newnum2/10;
	digit2of2 = newnum2%10;
	newnum2 = newnum2/10;
	digit1of2 = newnum2%10;
	newnum2 = newnum2/10;

	sum = (((digit1of1+digit1of2)/2)*1000);
	sum = sum + (((digit2of1+digit2of2)/2)*100);
	sum = sum + (((digit3of1+digit3of2)/2)*10);
	sum = sum + (((digit4of1+digit4of2)/2)*1);
	
	printf("\nThe sum of the nums is: %d \n", sum);
}




	
	
	
	
