#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define PORT 8080

int main(int argc,char *argv[])
{
	int sock = 0,valread;
	struct sockaddr_in serv_addr;
	
	char *hello = "Welcome from client";
	char buffer[1024] = {0};
	
	if( (sock =socket(AF_INET,SOCK_STREAM,0)) <0 )
	{
		printf("\n Error in socket creation");
		exit(EXIT_FAILURE);
	}
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Convert IPv4 and IPv6 Addresses from text to binary form
	
	if(inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr) <=0)
	{
		printf("\n Invalid address / address not supported ");
		exit(EXIT_FAILURE);	
	}

	// Connect to the server 
	
	if( connect( sock,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
	{
		printf("\n Connection Failed");
		exit(EXIT_FAILURE);	
	}

	send(sock,hello,sizeof(hello),0);
	printf("\nHello message sent");
	
	valread = read(sock,buffer,1024);
	
	printf("\n%s\n",buffer);
		
	return 0;
}
