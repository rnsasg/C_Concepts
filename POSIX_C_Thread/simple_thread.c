#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void myfunction()
{

	printf("\n New thread has started : %d \n",pthread_self());
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	printf("Welcome");

	if( pthread_create(&tid,NULL,(void *)myfunction,NULL) != 0)
	{
		printf("Error in thread creation ");
		exit(EXIT_FAILURE);		
	}
	pthread_join(tid,NULL); //The pthread_join() function waits for the thread specified by
       				//thread to terminate.  If that thread has already terminated, then
       				//pthread_join() returns immediately
	return 0;
}

