#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX 50

int main( int argc , char *argv[])
{
	key_t key = ftok("shmfile",65);
	
	int shmid = shmget(key,1024,0666|IPC_CREAT);

	char *str = (char*) shmat(shmid,(void*)0,0);

	printf("\n Writing data :\n");

	fgets(str,MAX,stdin);

	printf("\n Data written in memory : %s\n",str);

	shmdt(str);

	return 0;
}
