#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int parent_pid=getpid();
	char key[] = "done";
	FILE *IN_C, *N_C, *N_P;
	int pid=fork();
	if (pid==0)
	{
		int child_pid=getpid();
		int n=0;
		char IN_Cn[20],N_Cn[20],N_Pn[20],note[10];
		sprintf(IN_Cn,"input_{c}",child_pid);
		sprintf(N_Cn,"notify_{c}",child_pid);
		sprintf(N_Pn,"notify_{p}",parent_pid);
		while(1)
		{
			note[0]=0;
			printf("\nEnter a number: ");
			scanf("%d", &n);

			IN_C = fopen(IN_Cn, "w");
			fprintf(IN_C,"%d",n);
			fclose(IN_C);

			N_P = fopen(N_Pn, "w");
			fprintf(N_P, "done");
			fclose(N_P);

			N_C = fopen(N_Cn, "r");
			fgets(note,10,N_C);
			fclose(N_C);
			while (1)//strncmp(note,key,4)!=0)
			{
				if (note[0]=='d') break;
				N_C = fopen(N_Cn, "r");
				fgets(note,10,N_C);
				fclose(N_C);
			}

			N_C = fopen(N_Cn, "w");
			fclose(N_C);
		}
	}
	else
	{
			
			int child_pid=pid,n=0,r=0,fact=1;
			char IN_Cn[20],N_Cn[20],N_Pn[20],note[10];
			sprintf(IN_Cn,"input_{c}",child_pid);
			sprintf(N_Cn,"notify_{c}",child_pid);
			sprintf(N_Pn,"notify_{p}",parent_pid);
		while (1)
		{
			N_P=NULL;
			note[0]=0;
			while (N_P == NULL)
				N_P = fopen(N_Pn, "r");
			fgets(note,10,N_P);
			fclose(N_P);
	
			while (1)//strncmp(note,key,4)!=0)
			{
				if (note[0]=='d') break;
				N_P = fopen(N_Pn, "r");
				fgets(note,10,N_P);
				fclose(N_P);
			}
			N_P = fopen(N_Pn, "w");
			fclose(N_P);

			IN_C = fopen(IN_Cn, "r");
			fscanf(IN_C,"%d",&n);
			fclose(IN_C);

			for(r=1;r<=n;r++) 
				fact=fact*r;
			printf("%d\n", fact);
			fact=1;
			N_C = fopen(N_Cn, "w");
			fprintf(N_C, "done");
			fclose(N_C);
		}
	}
	
}
