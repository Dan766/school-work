#include <stdio.h>

//Function prototypes
//Function that Calculates the Rows
void ColCalc (float [4][3], float [4]);
//Function that Calculates the Columns
void RowCalc (float [4][3], float [3]);
//Function that prints out the chart at the end
void print_total (float [4][3], float [3], float [4], char [3][20]);

//Main function 
void main(void) 
{
	//Input Variables
	int r, c;
	float sales[4][3];
	char names[3][20];
	
	//Output Variables
	float Rsum[3], Csum[4];
	
	//For loop prompts the user to enter the names of the three employees
	for (c=0; c<3; c++)
	{
		printf("Enter the name of employee %d: ",c+1);
		scanf("%s",names[c]);
	}
	//For loop prompts the user to enter the Q1-Q4 sales for each of the three employees
	for (c=0; c<3; c++)
	{
		printf("Input the Quarter sales for the employee %s :\n",names[c]);
		for (r=0; r<4; r++)
		{
			printf("\tQ%d: ",r+1);
			scanf("%f",&sales[r][c]);
		}
		printf("\n");
	}
	//Calls function to compute the Columm sum of the data (Total Quarterly Sales)
	ColCalc (sales, Csum);
	//Calls function to compute the Row sum of the data (Total Personal Sales)
	RowCalc (sales, Rsum);
	//Calls the function that prints out all of our data onto a chart
	print_total(sales, Rsum, Csum, names);
}
//Function definition for the RowCalc function
//computes the Columm sum of the data (Total Quarterly Sales)
void ColCalc (float sales[4][3], float Csum[4])
{
	//Variables used for processing
	int c, r;
	// Calculates the sum of columns 
	for (r=0; r<4; r++)
	{
		Csum[r] = 0;
		for (c=0; c<3; c++)
		{
			Csum[r] += sales[r][c];
		}
	}
}
//Function definition for the CowCalc function
//computes the Row sum of the data (Total Personal Sales)
void RowCalc (float sales[4][3], float Rsum[3])
{
	//Variables used for processing 
	int c, r;
	//Calculates the sum of the rows
	for (c=0; c<3; c++)
	{
		Rsum[c] = 0;
		for (r=0; r<4; r++)
		{
			Rsum[c] += sales[r][c];
		}
	}
}
//Function definition for our print_total 
//function that prints out all of our data onto a chart
void print_total (float sales[][3], float Rsum[3], float Csum[4], char names[3][20])
{
	//variables used in printing the data
	int c, r;
	//Output variable 
	float total=0;
	//Prints the header for the table
	printf("Name:\t\tQ1\t\tQ2\t\tQ3\t\tQ4\t\tPersonal Sales\n");
	//Prints each employees name and sales numbers for each quarter
	for (c=0; c<3; c++)
	{
		printf("%s:",names[c]);
		for (r=0; r<4; r++)
		{
			printf("\t%.2f",sales[r][c]);
		}
		printf("\t%.2f",Rsum[c]);
		total += Rsum[c];
		printf("\n");
	}
	//Prints the sales amounts for each quarter 
	printf("Quarterly Sales:");
	for (r=0; r<4; r++)
	{
		printf("\t%.2f",Csum[r]);
	}
	//Prints the 'footer' for the table; includes a containing line and the total sales
	printf("\n");
	printf("----------------------------------------------------------------------------------------");
	printf("\nTotal:\t\t\t\t\t\t\t\t\t\t%.2f\n\n", total);
}
