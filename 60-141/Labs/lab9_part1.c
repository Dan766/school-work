#include <stdio.h>
struct employee{
	char firstname[40];
	char lastname[40];
	int id;
	float GPA;
};
typedef struct employee Employee;
/* Input the employee data interactively from the keyboard */
void InputEmpRecord(Employee *EmpList); 
/* Display the contents of Employee records from the list */
void PrintEmpList(const Employee *EmpList); 
/* Save the employee records from the list to the newly created text file specified by FileName */
void SaveEmpList(const Employee *EmpList, const char *FileName);

int main() 
{
	FILE *FP;
	Employee EmpList[4];
	InputEmpRecord(EmpList); //Prompts user to input data
	PrintEmpList(EmpList); //Prints data onscreen
	SaveEmpList(EmpList, "employee.dat"); //Saves data to text file
	return 0; //Program End
}
/*
	Objective: This function will read data from input and save it in a structure
*/
void InputEmpRecord(Employee *EmpList)
{
	int r=0;
	printf("ENTER: StudentID Firstname Lastname GPA:\n");
	for (r=0;r<4;r++) 
		scanf("%d %s %s %f", &EmpList[r].id, EmpList[r].firstname, EmpList[r].lastname, &EmpList[r].GPA); //reads info
}
/*
	Objective: The objective of this function is to write data saved in a structure to a file
*/
void SaveEmpList(const Employee *EmpList, const char *FileName)
{
	int r;
	FILE *FP;
	FP = fopen(FileName, "wb");
	fwrite(&EmpList,sizeof(Employee),4,FP);
	fclose(FP);
}
/*
	Objective: The objective of this function is to print the contents of the employee structure
*/
void PrintEmpList(const Employee *EmpList)
{
	int r=0;
	for (r=0;r<4;r++)
		printf("\n%d %s %s %.1f",EmpList[r].id,EmpList[r].firstname,EmpList[r].lastname,EmpList[r].GPA);
}
