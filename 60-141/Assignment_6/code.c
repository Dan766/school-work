#include<stdio.h>
#include<string.h>
typedef struct{
	int ID;
	float grades[10];
	float GPA;
}i_t;
int main() 
{
	FILE *FP,*FP2;
	FP = fopen("assign6.dat","r"); //Opens Input File
	FP2 = fopen("assign6out.dat","wb"); //Opens processing file (used for sort)
	i_t A; 
	int r=0,d,c,bytes_f=0,bytes_s=0;
	char S[100];
	while(!feof(FP)) //Runs until File has reached end
	{
		fgets(S,100,FP);
		bytes_f+=strlen(S); //Calculates size in bytes of input line
		bytes_s+=sizeof(i_t); //Calculates size in bytes of structure line
		sscanf(S,"%d %f %f %f %f %f %f %f %f %f %f",&A.ID,&A.grades[0],&A.grades[1],
			&A.grades[2],&A.grades[3],&A.grades[4],&A.grades[5],
			&A.grades[6],&A.grades[7],&A.grades[8],&A.grades[9]);
		//Calculate GPA
		A.GPA=0;
		for (c=0;c<10;c++)
			A.GPA+=A.grades[c];
		A.GPA/=10;
		//Output structure to assign6out.dat:
		fseek(FP2,r*sizeof(i_t),SEEK_SET);
		fwrite(&A,sizeof(i_t),1,FP2);
		r++; //Record counter
	}
	fclose(FP); //Closes input file
	fclose(FP2);//Closes processing file
	i_t Std1, Std2; //Creates two structures used for sorting the file
	FP = fopen("assign6out.dat", "rb+"); //Open assign6out.dat for reading
	//SORT IN PLACE: 
	for(d=0;d<r-1;d++) //BUBBLE SORT
	{
		for(c=0;c<r-1;c++)
		{
			fseek(FP,c*sizeof(i_t),SEEK_SET);
			fread(&Std1, sizeof(i_t), 1, FP);//Read student c and save to Structure Std1
			fread(&Std2, sizeof(i_t), 1, FP);//Read student c+1 and save to Structure Std2
			if(Std1.ID>Std2.ID)//Compare ID of Student c with ID of studnet c+1
			{
				fseek(FP,c*sizeof(i_t),SEEK_SET); 	//Perform
				fwrite(&Std2,sizeof(i_t),1,FP);		//A
				fwrite(&Std1,sizeof(i_t),1,FP);		//Swap
			}
		}
	}
	FP2 = fopen("assign6results.dat", "w"); //Open the file for reading
	for (c=0;c<r;c++) //Print the file contents
	{
		fseek(FP,c*sizeof(i_t),SEEK_SET);
		fread(&Std1, sizeof(i_t), 1, FP);//Reads the data into Std1
		//Outputs the data to output file
		fprintf(FP2,"%d %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\tGPA: %.2f\n",Std1.ID,
			Std1.grades[0],Std1.grades[1],Std1.grades[2],Std1.grades[3],Std1.grades[4],
			Std1.grades[5],Std1.grades[6],Std1.grades[7],Std1.grades[8],Std1.grades[9],Std1.GPA);
	}
	//Prints size in bytes of files
	fprintf(FP2,"Size of assign6.dat: %d Bytes\nSize of assign6out.dat: %d Bytes",bytes_f,bytes_s);
	fclose(FP2); //Close the File
	fclose(FP); //Close the File
	return 0; //Program End
}
