#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
int sockfd,n;
char sendline[100];
char recvline[100];
struct sockaddr_in servaddr;
sockfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof servaddr);
bzero( sendline, 100);
bzero( recvline, 100);
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(27000);
servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
while(1)
{
fgets(sendline,100,stdin); 

send(sockfd,sendline,sizeof(sendline),0);

if(strcmp(sendline,"exit\n")==0)
{
break;
}

recv(sockfd,recvline,sizeof(recvline),0);

if(strcmp(recvline,"exit\n")==0)
{
break;
}

printf("%s",recvline);
}
}
