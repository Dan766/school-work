#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	FILE *FP1,*FP2;
	char name[10];
	int d,size[2],r,c;
	FP1 = fopen(argv[1],"rb");
	FP2 = fopen(argv[2],"wb");
	fscanf(FP1, "%s %d %d %d", name, &size[0], &size[1], &d);
	fprintf(FP2, "%s\n%d %d\n%d\n", name, size[0], size[1], d);
	fseek(FP1,1,SEEK_CUR);
	unsigned char buff[size[1]];
	unsigned char row[size[1]*3];
	for(r=0;r<3;r++)
	{
		fread(&row,sizeof(row),1,FP1);
		for (d=(size[0]*(size[1]-1));d<size[1]*size[0];d++) //Saves last col to buffer
			buff[d-size[0]*(size[1]-1)]=row[d];
		for (c=(size[0]*(size[1]-1));c>=0;c--)	//Shifts first and middle cols to right
			row[c+size[0]]=row[c];
		for(c=0;c<size[1];c++)	//Outputs buffer to first col
			row[c]=buff[c];
		fwrite(&row,sizeof(row),1,FP2);
	}
	fclose(FP1);
	fclose(FP2);
	return 0;
}
