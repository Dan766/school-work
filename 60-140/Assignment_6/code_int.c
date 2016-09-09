#include <stdio.h>
#include <math.h>

//Calculate payment Function prototype 
float calculate_payment(float, int, float);
void RowCalc (int [][], int []);
void ColCalc (int [][], int []);
void print_total (int [][], int [], int [], char [3][20]);

//Main function 
void main(void) 
{
	int r, c;
	int sales[4][3], Rsum[3], Csum[4];
	char names[3][20];
	for (c=0; c<3; c++)
	{
		printf("Enter the name of employee %d: ",c+1);
		scanf("%s",names[c]);
	}
	for (c=0; c<3; c++)
	{
		printf("Input the Quarter sales for the employee %s :\n",names[c]);
		for (r=0; r<4; r++)
		{
			printf("\tQ%d: ",r+1);
			scanf("%d\n",&sales[r][c]);
		}
		printf("\n");
	}
	
	RowCalc (sales, Csum);
	ColCalc (sales, Rsum);
	
	print_total(sales, Rsum, Csum, names);
}
void RowCalc (int sales[4][3], int Csum[4])
{
	int c, r;
	for (r=0; r<4; r++)
	{
		Csum[r] = 0;
		for (c=0; c<3; c++)
		{
			Csum[r] += sales[r][c];
		}
	}
}
void ColCalc (int sales[4][3], int Rsum[3])
{
	int c, r;
	for (c=0; c<3; c++)
	{
		Rsum[c] = 0;
		for (r=0; r<4; r++)
		{
			Rsum[c] += sales[r][c];
		}
	}
}
void print_total (int sales[][3], int Rsum[3], int Csum[4], char names[3][20])
{
	int c, r;
	float total=0;
	printf("Name:\t\tQ1\tQ2\tQ3\tQ4\tPersonal Sales\n");
	for (c=0; c<3; c++)
	{
		printf("%s:",names[c]);
		for (r=0; r<4; r++)
		{
			printf("\t%d",sales[r][c]);
		}
		printf("\t%d",Rsum[c]);
		total += Rsum[c];
		printf("\n");
	}
	printf("Quartly Sales:");
	for (r=0; r<4; r++)
	{
		printf("\t%d",Csum[r]);
	}
	printf("\n");
	printf("-------------------------------------------------------------");
	printf("\t\t\t\t\t\t%.2f", total);
}
