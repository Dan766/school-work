#include <stdio.h> 
#include <math.h>

// Function definitions 
double Mean (void);
double DevScore(float, float);
double SqDev(float, float);
void calculate(void);
void printfunc(void);

// Global Input variables 
float score1, score2, score3, score4, score5;
// Global Output variables
float mean, SqDev1, SqDev2, SqDev3, SqDev4, SqDev5, sum_SqDev,DevScore1,DevScore2,DevScore3,DevScore4,DevScore5, sd;
	
// Main porgram module 
int main(void)
{

	// Requests user to enter 5 test scores 
	printf("\nPlease type the 5 test scores: ");
	scanf("%f %f %f %f %f", &score1, &score2, &score3, &score4, &score5);
	
	// Performs calculations on data
	calculate();

	// Output text printed in a table format including all output data
	printfunc();
	
}

// Definitions for call_by_reference functions used in main program 
//function that calculates mean of 5 numbers
double Mean(void)
{
	return ((score1+score2+score3+score4+score5)/5);
}
// Function that caclulates squared deviation
double SqDev(float x, float m)
{
	return (pow(x-m, 2));
} 
// Function that calculates deviation score
double DevScore(float x, float m)
{
	return (x-m);
}
void calculate(void)
{	
	//Calculates mean
	mean = Mean();
	
	// Calculates the Deviation Scores
	DevScore1 = DevScore(score1 , mean);
	DevScore2 = DevScore(score2 , mean);
	DevScore3 = DevScore(score3 , mean);
	DevScore4 = DevScore(score4 , mean);
	DevScore5 = DevScore(score5 , mean);
	
	// Calculates the Squared Deviation of each score
	SqDev1 = SqDev(score1, mean);
	SqDev2 = SqDev(score2, mean); 
	SqDev3 = SqDev(score3, mean); 
	SqDev4 = SqDev(score4, mean); 
	SqDev5 = SqDev(score5, mean); 
	
	// Calculates the sum of all the Squared Deviations
	sum_SqDev = SqDev1 + SqDev2 + SqDev3 + SqDev4 + SqDev5;
	sd = sqrt(sum_SqDev/5);
}
// Print fuction used to print table of results
void printfunc(void)
{
	printf("\nScore   -   Mean Score =  Deviation Score  Squared Deviation");
	printf("\n(X)             (M)            (X-M)           (X-M)^2");
	printf("\n-------------------------------------------------------------");
	printf("\n%.1f\t\t%.1f\t\t%.1f\t\t%.2f", score1, mean, DevScore1, SqDev1);
	printf("\n%.1f\t\t%.1f\t\t%.1f\t\t%.2f", score2, mean, DevScore2, SqDev2);
	printf("\n%.1f\t\t%.1f\t\t%.1f\t\t%.2f", score3, mean, DevScore3, SqDev3);
	printf("\n%.1f\t\t%.1f\t\t%.1f\t\t%.2f", score4, mean, DevScore4, SqDev4);
	printf("\n%.1f\t\t%.1f\t\t%.1f\t\t%.2f", score5, mean, DevScore5, SqDev5);
	printf("\n\t\t\t\t\tSum:\t%.2f" , sum_SqDev);
	printf("\nVariance = %.2f/5 = %.2f", sum_SqDev, sum_SqDev/5);
	printf("\nStandard deviation = SD = %.2f\n\n", sd);
}
