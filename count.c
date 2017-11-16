#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define NUM_CHILD 3


void sig_fn(int signo);

int main(int argc,char* argv[])
{
	pid_t P[NUM_CHILD];
	pid_t next;
	int i=0;
	int write;
	FILE *fp;
	int number,Number;
	char num[256];
	Number = atoi(argv[1]);
	if (Number <= 0)
	{
		printf("input error\n");
		return 1;
	}
	else
	{
		fp = fopen(argv[2], "w");
		sprintf(num,"%d",0);
		fwrite(num,sizeof(char),1,fp);
		for(i=0; i<NUM_CHILD; i++) 
		{
        		if(fork() ==  0)                /* break if child process */
			{
				next = getpid()+1;
			}		
    		}

		if (next == getppid()+4)               //connect
			next = getppid()+1;
		fread(num,1,1,fp); // read
		write = atoi(num);
		while(write<Number) //run
		{
			
			sprintf(num,"%d",write+1); // plus and change
			fwrite(num,sizeof(char),sizeof(num),fp);	//write
			kill(getpid(),SIGSTOP); //keep mind
			kill(next,SIGCONT);// go next
		}
		return 1;
	}
}

