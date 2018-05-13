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
	fprintf(FP2, "%s\n%d %d\n%d\n", name, size[0], size[1], d);
	int R[size[0]][size[1]],G[size[0]][size[1]],B[size[0]][size[1]];
	int r,c;
	for(r=0;r<3;r++)
	{
		for (c=0;c<3*size[0];c++)
		{
			if (c<size[0]) fscanf(FP1, "%d", &R[r][c]);
			else if (c<2*size[0]) fscanf(FP1, "%d", &G[r][c]);
			else fscanf(FP1, "%d", &B[r][c]);
			if (((*argv[3]-48)==1)&&(R[r][c]>=50)) R[r][c]-=50;
			else if (((*argv[3]-48)==2)&&(G[r][c]>=50)) G[r][c]-=50;
			else if (((*argv[3]-48)==3)&&(B[r][c]>=50)) B[r][c]-=50;
		}
	}
	fclose(FP1);
	for(r=0;r<3;r++)
	{
		for (c=0;c<3*size[0];c++)
		{
			if (c<size[0]) fprintf(FP2, "%3d ", R[r][c]);
			else if (c<2*size[0]) fprintf(FP2, "%3d ", G[r][c]);
			else fprintf(FP2, "%3d ", B[r][c]);
		}
		fprintf(FP2, "\n");
	}
	fclose(FP2);
	return;
}
