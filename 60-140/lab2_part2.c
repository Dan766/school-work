#include <stdio.h>
int main()
{
	//Input Variables
	float temp_in_fer;
	//Output Variables
	float temp_in_c;
	
	printf( "Type the temp in Farhrenheit (F) you want converted to Celsius (C): ");
	scanf("%f", &temp_in_fer);
	
	temp_in_c = (((temp_in_fer-32)*5) / 9);
	
	printf("%.1f F is equivalent to: %.1f C\n", temp_in_fer, temp_in_c);
	return 0;
}
