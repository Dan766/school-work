#include <stdio.h>
#include <math.h>

//Calculate payment Function prototype 
float calculate_payment(float, int, float);

//Main function 
void main(void) 
{
	//INPUT variables
	float interest_rate, principal;
	int term;
	char newpay;
	
	//OUTPUT variables
	float monthly_interest_rate, monthly_payment;
	
	//Asks the user if they would like to compute a new monthly rate
	do
	{
		printf("\nPlease type Y if you want us to compute the monthly Rate for new data and N otherwise:");
		scanf(" %s", &newpay);
		//If a invalid command is entered (not n or y), the user is notified 
		if ((newpay != 'y')&&(newpay != 'N')&&(newpay != 'n')&&(newpay != 'Y'))
		{
			printf("\n***INVALID INPUT!***\n");
		}
		//Loop until a valid command is entered (y or n)
	} while ((newpay != 'y')&&(newpay != 'N')&&(newpay != 'n')&&(newpay != 'Y'));
	
	//If the user typed 'y' or 'Y', the program will ask them for their loan information
	while ((newpay!='n')&&(newpay!='N')) 
	{
		//Prompts user to enter the principal investment
		printf("\nPlease enter the loan amount in Dollars:\t");
		scanf("\t%f", &principal);
		//Prompts user to enter the Interest Rate
		printf("Please enter the Annual Interest Rate:\t\t");
		scanf("\t%f", &interest_rate);
		//Prompts user to enter the loan term
		printf("Please enter the loan term in months:\t\t");
		scanf("\t%d", &term);
	
		//Calls the calculate_payment function to calculate the monthly payment
		monthly_payment = calculate_payment(interest_rate, term, principal);	
	
		//Prints the principal investment
		printf("\nWhen:\tThe loan amount is:\t$%.2f",principal);
		//Prints the interest_rate
		printf("\n\tThe Annual interest is:\t%0.0f%%", interest_rate);
		//Prints the loan term
		printf("\n\tThe Loan term is:\t%d months", term);
		//Prints the monthly payment
		printf("\n\nThe monthly payment is:\t$%.2f\n", monthly_payment);
		//Asks the user if they would like to compute a new monthly rate
		do
		{
			printf("\nPlease type Y if you want us to compute the monthly Rate for new data and N otherwise:");
			scanf(" %s", &newpay);
			//If a invalid command is entered (not n or y), the user is notified 
			if ((newpay != 'y')&&(newpay != 'N')&&(newpay != 'n')&&(newpay != 'Y'))
			{
				printf("\n***INVALID INPUT!***\n");
			}
		//Loop until a valid command is entered (y or n)
		} while ((newpay != 'y')&&(newpay != 'N')&&(newpay != 'n')&&(newpay != 'Y'));
	}
	//User is notified of the programs end
	printf("\nThank you \nPlease visit us again!!!\n***\n\n");
}

//Calculate payment function 
float calculate_payment(float interest_rate, int term, float amount)
{
	//Varibles used in calculation
	float expm, monthly_payment,monthly_interest_rate;
	char case1;
	//Assigns a case letter for use with switch_case corresponding to a term interval
	//if term <= 12, case1 = 'A'
	if (term <= 12)
	{
		case1 = 'A';
	}
	else 
		{
		//if term !(<=) 12 and term <= 24, case = 'B'
		if (term <= 24)
		{
			case1 = 'B';
		}
		else
		{
			//if term !(<=) 24 and term <= 36, case = 'C'
			if (term <= 36)
			{
				case1 = 'C';
			}
			//if term !(<=) 36, case = 'D'
			else
			{
				case1 = 'D';
			}
		}
		}
	//Switch_Case on the expression case1
	switch (case1)
	{
	//If case1 ='A', interest rate will be un modified 
	case 'A': 
		monthly_interest_rate = interest_rate / term;
		break;
	//If case1 ='B', interest rate will be multiplied by 1.05
	case 'B':
		monthly_interest_rate = interest_rate*1.05 / term;
		break;
	//If case1 ='C', interest rate will be multiplied by 1.15
	case 'C':
		monthly_interest_rate = interest_rate*1.15 / term;
		break;
	//If case1 ='D', interest rate will be multiplied by 1.25
	case 'D':
		monthly_interest_rate = interest_rate*1.25 / term;
		break;
	}
	//Sets the montly interest rate equal to the rate /100
	monthly_interest_rate = monthly_interest_rate/100;
	//Sets eulars number equal to the monthly rate + 1
	expm = monthly_interest_rate + 1;
	//Evaluates the monthly payment 
	monthly_payment = (monthly_interest_rate * pow(expm,term) * amount)/(pow(expm,term) -1);
	//Returns the monthly payment back to the main function 
	return (monthly_payment);
}	
	
