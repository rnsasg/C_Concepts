#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler()
{
	printf("Sig Handlder called");
}

int main( int argc , char* argv[] )
{
	signal(SIGALRM,signal_handler);
	alarm(10);
	printf("\n Sleeping for 10 seconds \n");
	sleep(11);
	return 0;
}
