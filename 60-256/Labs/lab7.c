#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int c=1,pid=0;
	char cmd[100];
	while((c<argc-1)&&(pid==0))
	{
		sprintf(cmd, "%s %s", argv[c], argv[c+1]);
		system(cmd);
		printf("The PID is: %d\n\n",getpid());
		pid=fork();
		wait(NULL);
		if (pid>0) return;
		c+=2;
	}
	if (argc%2==0)
	{
		sprintf(cmd, "%s", argv[c]);
		system(cmd);
		printf("The PID is: %d\n",getpid());
	}
	return;
}
