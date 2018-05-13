#include <stdio.h>
struct employee{
	char firstname[40];
	char lastname[40];
	int id;
};
typedef struct employee Employee;
/* Input the employee data interactively from the keyboard */
void WordCap(char *); 
//Main Function
int main() 
{
	int r;
	char data[100];
	FILE *FP;
	Employee EmpList[3];
	FP = fopen("employee.dat", "r");
	for (r=0;r<3;r++)
	{
		fscanf(FP, "%d %s %s\n", &EmpList[r].id, EmpList[r].firstname, EmpList[r].lastname);
		WordCap(EmpList[r].firstname); //makes first letter of firstname uppercase
		WordCap(EmpList[r].lastname); //Makes first letter of lastname uppercase
	}
	fclose(FP);

	FP = fopen("employee.dat", "w"); //Open file for writing
	for(r=0;r<3;r++) fprintf(FP, "%d %s %s\n", EmpList[r].id, EmpList[r].firstname, EmpList[r].lastname); //writes data to file
	fclose(FP); //Closes the file / Saves
}
/*
	Objective: Takes a pointer to string as input and will make the first letter uppercase
*/
void WordCap(char *word)
{
	*word = toupper(*word); //makes the char pointed to by word uppercase
}
