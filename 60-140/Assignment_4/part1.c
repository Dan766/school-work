#include <stdio.h> 
#include <math.h>

// Function definitions 
float Mean (float, float, float, float, float);
float DevScore(float, float);
float SqDev(float, float);
void calculate(float,float,float,float,float,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *);
void printfunc(float,float,float,float,float,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *,float *);
	
// Main porgram module 
void main(void)
{
	// Input variables 
	float score1, score2, score3, score4, score5;
	// Output Variables
	float mean, SqDev1, SqDev2, SqDev3, SqDev4, SqDev5, sum_SqDev,DevScore1,DevScore2,DevScore3,DevScore4,DevScore5, sd;
	
	// Requests user to enter 5 test scores 
	printf("\nPlease type the 5 test scores: ");
	scanf("%f %f %f %f %f", &score1, &score2, &score3, &score4, &score5);
	
	// Performs calculations on data
	calculate(score1, score2, score3, score4, score5,&SqDev1,&SqDev2,&SqDev3,&SqDev4,&SqDev5,&DevScore1,&DevScore2,&DevScore3,&DevScore4,&DevScore5,&sum_SqDev,&sd, &mean);

	// Output text printed in a table format including all output data
	printfunc(score1, score2, score3, score4, score5,&SqDev1,&SqDev2,&SqDev3,&SqDev4,&SqDev5,&DevScore1,&DevScore2,&DevScore3,&DevScore4,&DevScore5,&sum_SqDev,&sd, &mean);
	
}

// Definitions for call_by_reference functions used in main program 
//function that calculates mean of 5 numbers
float Mean(float score1, float score2, float score3, float score4,float score5)
{
	return ((score1+score2+score3+score4+score5)/5);
}
// Function that caclulates squared deviation
float SqDev(float x, float m)
{
	return (pow(x-m, 2));
} 
// Function that calculates deviation score
float DevScore(float x, float m)
{
	return (x-m);
}
// Function that does all calculations
void calculate(float score1,float score2,float score3,float score4,float score5,float *SqDev1,float *SqDev2,float *SqDev3,float *SqDev4,float *SqDev5,float *DevScore1,float *DevScore2,float *DevScore3,float *DevScore4,float *DevScore5,float *sum_SqDev,float *sd, float *mean)
{	
	//Calculates mean
	*mean = Mean(score1, score2, score3, score4, score5);
	
	// Calculates the Deviation Scores
	*DevScore1 = DevScore(score1 , *mean);
	*DevScore2 = DevScore(score2 , *mean);
	*DevScore3 = DevScore(score3 , *mean);
	*DevScore4 = DevScore(score4 , *mean);
	*DevScore5 = DevScore(score5 , *mean);
	
	// Calculates the Squared Deviation of each score
	*SqDev1 = SqDev(score1, *mean);
	*SqDev2 = SqDev(score2, *mean); 
	*SqDev3 = SqDev(score3, *mean); 
	*SqDev4 = SqDev(score4, *mean); 
	*SqDev5 = SqDev(score5, *mean); 
	
	// Calculates the sum of all the Squared Deviations
	*sum_SqDev = *SqDev1 + *SqDev2 + *SqDev3 + *SqDev4 + *SqDev5;
	*sd = sqrt(*sum_SqDev/5);
}
// Print fuction used to print table of results
void printfunc(float score1,float score2,float score3,float score4,float score5,float *SqDev1,float *SqDev2,float *SqDev3,float *SqDev4,float *SqDev5,float *DevScore1,float *DevScore2,float *DevScore3,float *DevScore4,float *DevScore5,float *sum_SqDev,float *sd, float *mean)
{
	printf("\nScore   -   Mean Score =  Deviation Score  Squared Deviation");
	printf("\n(X)             (M)            (X-M)           (X-M)^2");
	printf("\n-------------------------------------------------------------");
	printf("\n%.1f\t\t%.1f\t\t%.1f\t\t%.2f", score1, *mean, *DevScore1, *SqDev1);
	printf("\n%.1f\t\t%.1f\t\t%.1f\t\t%.2f", score2, *mean, *DevScore2, *SqDev2);
	printf("\n%.1f\t\t%.1f\t\t%.1f\t\t%.2f", score3, *mean, *DevScore3, *SqDev3);
	printf("\n%.1f\t\t%.1f\t\t%.1f\t\t%.2f", score4, *mean, *DevScore4, *SqDev4);
	printf("\n%.1f\t\t%.1f\t\t%.1f\t\t%.2f", score5, *mean, *DevScore5, *SqDev5);
	printf("\n\t\t\t\t\tSum:\t%.2f" , *sum_SqDev);
	printf("\nVariance = %.2f/5 = %.2f", *sum_SqDev, *sum_SqDev/5);
	printf("\nStandard deviation = SD = %.2f\n\n", *sd);
}
