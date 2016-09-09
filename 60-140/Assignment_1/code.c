//Assignment 1: 60-140 
//By Daniel Fontana
#include <stdio.h>
int main(void)
{
	//Input Variables
	float weight_in_lbs, temp_in_fer, dist_in_miles, dist_in_yards, dist_in_inches; 
	//Output Variables
	float weight_in_kg, temp_in_c, dist_in_km, dist_in_meters, dist_in_cm;
	
	//Prints a title along with my name
	printf("\n\tAssignment 1: 60-140");
	printf("\n\t   Daniel Fontana");
	printf("\n\t********************");
	
	//Requests user to enter in the float values that they wish to have converted
	printf( "\nType the number of lbs you want to convert to Kg: ");
	scanf("%f", &weight_in_lbs);
	printf( "Type the number of F you want converted to C: ");
	scanf("%f", &temp_in_fer);
	printf( "Type the number of miles you want converted to Kilometers: ");
	scanf("%f", &dist_in_miles);
	printf( "Type the number of yards you want converted to meters: ");
	scanf("%f", &dist_in_yards);
	printf( "Type the number of inches you want converted to centimeters: ");
	scanf("%f", &dist_in_inches);
	
	//Performs operations on the entered values to convert them
	weight_in_kg = weight_in_lbs*.453592;
	temp_in_c = (((temp_in_fer-32)*5) / 9);
	dist_in_km = dist_in_miles*1.60934;
	dist_in_meters = dist_in_yards*.9144;
	dist_in_cm = dist_in_inches*2.54;
	
	//Prints out the original values along with the new converted ones
	printf("\n%.1f lbs is equivalent to: %.3f kg\n", weight_in_lbs, weight_in_kg);
	printf("%.1f F is equivalent to: %.3f C\n", temp_in_fer, temp_in_c);
	printf("%.1f miles is equivalent to: %.3f km\n", dist_in_miles, dist_in_km);
	printf("%.1f yards is equivalent to: %.3f meters\n", dist_in_yards, dist_in_meters);
	printf("%.1f inches is equivalent to: %.3f cm\n", dist_in_inches, dist_in_cm);
	return 0;
}

