#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 50


struct mseg_buffer {

	long mesg_type;
	char mesg_text[100];
}message;

int main(int argc , char *argv[])
{
	key_t key;
	int msgid;

	// Generate a unique key
	key = ftok("progfile",65);
	
	msgid = msgget(key,0666 | IPC_CREAT);
	message.mesg_type = 1;

	printf(" Writing data :");
	fgets(message.mesg_text,MAX,stdin);


	msgsnd(msgid, &message , sizeof(message) , 0);

	printf(" Data send is : %s \n",message.mesg_text);
		
	return 0;
}
