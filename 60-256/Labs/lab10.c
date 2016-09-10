#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/signal.h>
void CNTRL_handle()
{
	printf("\nControl C called\n");
	exit(2);
}
void CNTRLZ_handle()
{
	printf("\nControl Z called\n");
	exit(2);
}
int main(int argc, char *argv[])
{
	signal(SIGINT,CNTRL_handle);
	signal(SIGTSTP,CNTRLZ_handle);
	int fd[2];	
	pipe(fd);
	int parent_pid=getpid();
	char key[] = "done";
	FILE *IN_C, *N_C, *N_P;
	int pid=fork();
	if (pid==0)
	{
		int child_pid=getpid();
		int r,n;
		char IN_Cn[20],N_Cn[20],N_Pn[20],note[10];
		while(1)
		{
			close(fd[0]);			
			printf("\nEnter a number: ");
			scanf("%d", &n);
	
			write(fd[1],&n,sizeof(int));
			sleep(1);


		}
	}
	else
	{
			
			int child_pid=pid,r=0,fact=1,q,num=0,nums[10];
			char IN_Cn[20],N_Cn[20],N_Pn[20],n[10];
		while (1)
		{
			close(fd[1]);			
			fact=1;
			read(fd[0],&n,sizeof(int));
			for(q=1;q<=*n;q++) 
				fact=fact*q;
			printf("%d\n", fact);

		}
	}
	
}
