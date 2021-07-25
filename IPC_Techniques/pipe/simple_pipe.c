#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main( int argc , char *argv[])
{
	int pipefds[2];
	int ret;
	int pid;

	char wrMsg[2][20]={"Hi","Hello"};
	char rdMsg[20];

	ret = pipe(pipefds);
	if( ret == -1 )
	{
		printf("\n Unable to create pipe");
		exit(EXIT_FAILURE);	
	}
	
	pid = fork();
	
	if( pid == 0 )
	{
		read(pipefds[0],rdMsg,sizeof(rdMsg));
		printf("\n Child Process - Reading from pipe - Message-1 is :- %s \n",rdMsg);
		read(pipefds[0],rdMsg,sizeof(rdMsg));
		printf("\n Child Process - Reading from pipe - Message-2 is :- %s \n",rdMsg);
	}
	else
	{
		printf("\n Parent Process - Writing to the pipe - Message 1 is %s \n",wrMsg[0]);
		write(pipefds[1],wrMsg[0],sizeof(wrMsg[0]));
		sleep(1);
		printf("\n Parent Process - Writing to the pipe - Message 1 is %s \n",wrMsg[1]);
		write(pipefds[1],wrMsg[1],sizeof(wrMsg[1]));
		
	}	
	return 0;	
}


