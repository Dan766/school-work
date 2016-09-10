#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	FILE *FP1,*FP2;
	char name[10];
	int d, size[2];
	FP1 = fopen(argv[1],"r");
	FP2 = fopen(argv[2],"w");
	fscanf(FP1, "%s %d %d %d", name, &size[0], &size[1], &d);
	fprintf(FP2, "%s\n%d %d\n%d\n", name, size[1], size[0], d);

	int A[size[1]][size[0]]; //A[8][31]
	int r,c;
	
	for (r=0;r<size[1];r++) //scan each 8 rows
	{
		for (c=0;c<size[0];c++) //scand each element
			fscanf(FP1, "%d", &A[r][c]);
	}
	fclose(FP1);
	
	//output flipped graph
	for (c=0;c<size[0];c++) //scan each 8 rows
	{
		for (r=size[1]-1;r>=0;r--) //scand each element
		{
			fprintf(FP2, "%d ", A[r][c]);
			printf("%d ", A[r][c]);

		}
		fprintf(FP2, "\n");
		printf("\n");

	}	
	fclose(FP2);
	return;
}
