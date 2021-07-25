#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct args {

	char *name;
	int age;
};

void myfunction(void *var)
{

	printf("\n %s :  Thread id is : %d \n",__func__,pthread_self());
	printf("\n Name : %s \n",((struct args*)var)->name);
	printf("\n Age : %d \n",((struct args*)var)->age);
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	char name[]="Narayan";

	struct args *input = ( struct args *)malloc (sizeof(struct args));

	input->name = name;
	input->age=28;
	
	if( pthread_create(&tid,NULL,(void *)myfunction,(void *)input) != 0)
	{
		printf("Error in thread creation ");
		exit(EXIT_FAILURE);		
	}
	pthread_join(tid,NULL); //The pthread_join() function waits for the thread specified by
       				//thread to terminate.  If that thread has already terminated, then
       				//pthread_join() returns immediately
	return 0;
}

