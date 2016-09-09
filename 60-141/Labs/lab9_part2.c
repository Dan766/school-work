#include <stdio.h>
struct employee{
	char firstname[40];
	char lastname[40];
	int id;
	float GPA;
};
typedef struct employee Employee;

//Main Function
int main() 
{
	int r=0,d,c;
	FILE *FP;
	Employee Emp1, Emp2;
	
	if ((FP = fopen("employee.dat", "rb+"))==NULL) //Open employee.dat for reading
		printf("ERROR");
	else
	{
		for(d=0;d<3;d++) //BUBBLE SORT
		{
			for(c=0;c<3;c++)
			{
				fseek(FP,c*sizeof(Employee),SEEK_SET);	//Read employee #c
				fread(&Emp1, sizeof(Employee), 1, FP);	//  and save to Structure Emp1
				//fseek(FP,(c+1)*sizeof(Employee),SEEK_SET);//Read employee #c+1
				fread(&Emp2, sizeof(Employee), 1, FP);    //  and save to Structure Emp2
				if(Emp1.GPA<Emp2.GPA)//Compare GPA of employee c with GPA of employee c+1
				{
					fseek(FP,c*sizeof(Employee),SEEK_SET); 		//
					fwrite(&Emp2,sizeof(Employee),1,FP);		//	Perform a
					//fseek(FP,(c+1)*sizeof(Employee),SEEK_SET);	//	swap operation
					fwrite(&Emp1,sizeof(Employee),1,FP);		//
				}
			}
		}
	}
	fclose(FP); //Close the File
	FP = fopen("employee.dat", "rb"); //Open the file for reading
	for (r=0;r<4;r++) //Print the file contents
	{
		fseek(FP,r*sizeof(Employee),SEEK_SET);
		fread(&Emp1, sizeof(Employee), 1, FP);
		printf("\n%d %s %s %.1f",Emp1.id,Emp1.firstname,Emp1.lastname,Emp1.GPA);
	}
	fclose(FP); //Close the File
	return 0;
}

