//Assignment 2: 60-140
//By Daniel Fontana
#include <stdio.h>
int main(void)
{
	//Input Variables
	float weight_week_0, weight_week_1, weight_week_2, weight_month_2;
	//Constants
	const float one_lbs_to_kg = .4545, one_kg_to_lbs = 2.2;
	//Output Variables
	float gain_week_1, gain_week_2, gain_month_2;

	//Prints a title
	printf("\n\tWelcome to the Kg to lbs Weighing Scale Converter");
	printf("\n\t**************************************************");
	
	printf("\nPlease type the Kg weight of the model in England: ");
	scanf("%f", &weight_week_0);
	printf("Please type the lbs weight of the model in Canada week 1: ");
	scanf("%f", &weight_week_1);
	printf("Please type the lbs weight of the model in Canada week 2: ");
	scanf("%f", &weight_week_2);
	printf("Please type the Kg weight of the model in England in 2 months: ");
	scanf("%f", &weight_month_2);
	
	gain_week_1 = weight_week_1-(weight_week_0*one_kg_to_lbs);
	gain_week_2 = weight_week_2-weight_week_1;
	gain_month_2 = weight_month_2-(weight_week_2*one_lbs_to_kg);
	
	printf("\nChange in the model's weight:");
	printf("\n\tGain in weight in Canada week 1: %.2f lbs", gain_week_1);
	printf("\n\tGain in weight in Canada week 1: %.2f lbs", gain_week_2);
	printf("\n\tGain in weight in England 2 months: %.2f kg\n", gain_month_2);
	
	printf("\nThank you for using the Kg to lbs Weighing Scale Converter.\nHave a nice day!\n\n");
	
	return 0;
}
