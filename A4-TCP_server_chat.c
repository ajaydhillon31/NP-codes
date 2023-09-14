#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
int main()
{
char recieved[100],sent[100];
int listen_fd, comm_fd;
struct sockaddr_in servaddr;
listen_fd = socket(AF_INET, SOCK_STREAM, 0);
bzero( &servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(27000);
bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
listen(listen_fd, 10);

comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);
while(1)
{
recv(comm_fd,recieved,sizeof(recieved),0);

if(strcmp(recieved,"exit\n")==0)
{
break;
}
printf("%s",recieved);

fgets(sent,100,stdin);

send(comm_fd,sent,sizeof(sent),0);

if(strcmp(sent,"exit\n")==0)
{
break;
}

}

}
