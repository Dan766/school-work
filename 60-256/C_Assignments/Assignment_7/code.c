#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	FILE *FP1,*FP2;
	int p=0;
	char name[10];
	int d, size[2];
	FP1 = fopen(argv[1],"r");
	fscanf(FP1, "%s %d %d %d\n", name, &size[0], &size[1], &d);
	FP2 = fopen(argv[2],"w");
	fprintf(FP2, "%s\n%d %d\n%d\n", name, size[0]*2-1,size[1]*2-1, d);
	fclose(FP2);
	int A[(size[1]*3)*2],R[size[1]],A1[size[0]][(size[1]*3)*2];
	int r,c,status,q;
	int new[size[1]*2*3];
	d=size[1]*2;
	for(r=0;r<=size[0];r++)
	{
		for (c=0;c<3*4;c++) fscanf(FP1,"%d",&A[c]);
		for (c=0;c<3*size[0];c++)
		{
			if (c<size[0]) 
			{
				R[c*2]=A[c];
				if ((c+1)!=size[0]) R[c*2+1]=(A[c]+A[c+1])/2;
				A1[r][c*2]=R[c*2];
				A1[r][c*2+1]=R[c*2+1];
			}
			else if (c<2*size[0]) 
			{
				if (c==size[0]) d=7;
				R[(c-size[0])*2]=A[c];
				if ((c+1)!=size[0]*2) R[(c-size[0])*2+1]=(A[c]+A[c+1])/2;
				A1[r][d]=R[(c-size[0])*2];
				A1[r][d+1]=R[(c-size[0])*2+1];
				d+=2;
			}
			else 
			{
				if (c==size[0]*2) d=14;
				R[(c-size[0]*2)*2]=A[c];
				if ((c+1)!=size[0]*3) R[(c-size[0]*2)*2+1]=(A[c]+A[c+1])/2;
				A1[r][d]=R[(c-size[0]*2)*2];
				A1[r][d+1]=R[(c-size[0]*2)*2+1];
				d+=2;
			}
		}
		if(p>0) 
		{
			sleep(1);
			printf("%d\n",p);
			kill (p,SIGCONT);		
		}	
		if ((r>0)&&(r<size[0]))
		{
			if((p=fork())==0)
			{		
				printf("ss\n");
				kill(getpid(),SIGSTOP);
				printf("done\n");		
				FP2 = fopen(argv[2],"r+");
				fseek(FP2,0,SEEK_END);
				for(c=0;c<size[1]*2*3-3;c++)
					new[c]=(A1[r-1][c]+A1[r][c])/2;
				for(c=0;c<size[1]*2*3-3;c++) 
					fprintf(FP2,"%d ",A1[r-1][c]);
				fprintf(FP2,"\n");
				for(c=0;c<size[1]*2*3-3;c++) 
					fprintf(FP2,"%d ",new[c]);
				fprintf(FP2,"\n");
				fclose(FP2);
				exit(1);
			}			
		}
	}
	sleep(1);
	FP2 = fopen(argv[2],"r+");
	fseek(FP2,0,SEEK_END);
	for(c=0;c<size[1]*2*3-3;c++) 
		fprintf(FP2,"%d ",A1[size[0]-1][c]);
	fclose(FP2);
	fclose(FP1);
}
