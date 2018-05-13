#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int pid,nums[3],num=0,r;
	int FP;
	char buff[3];
	FP = open("storage",O_RDWR);
	read(FP,buff,3);
	for (r=0;r<3;r++)
	{
		if (((buff[r]-48)<10)&&((buff[r]-48>-1))) nums[r]=buff[r]-48;
		else nums[r]=10;
	}
	for (r=0;r<3;r++)
	{
		if(nums[r]<10) 
		{
			num*=10;
			num+=nums[r];
		}
	}
	num-=3;
	sprintf(buff,"%d\0",num);
	printf("%s",buff);
	close(FP);
	FP=open("storage",O_RDWR|O_TRUNC);
	write(FP,buff,strlen(buff));
	close(FP);
	if(fork()==0) exeecvp(producer, argvp);
	else return 0;
	}
}
