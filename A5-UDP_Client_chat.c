#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
int main(int argc,char **argv)
{
int fd,n;
char sendmessage[100];
char recvmessage[100];
struct sockaddr_in saddr;
fd=socket(AF_INET,SOCK_DGRAM,0);
bzero(&saddr,sizeof saddr);
saddr.sin_family=AF_INET;
saddr.sin_port=htons(26005);
saddr.sin_addr.s_addr = inet_addr("127.0.0.1");

int len;
while(1)
{
bzero( sendmessage, 100);
bzero( recvmessage, 100);
fgets(sendmessage,100,stdin); /*stdin = 0 , for standard input */
sendto(fd,sendmessage,sizeof(sendmessage),0,(struct sockaddr*)&saddr,sizeof(saddr));
if(strcmp(sendmessage,"exit\n")==0)
{
break;
}
recvfrom(fd,recvmessage,sizeof(recvmessage),0,(struct sockaddr*)&saddr,&len);
if(strcmp(recvmessage,"exit\n")==0)
{
break;
}

printf("%s",recvmessage);

}
}


//recvfrom(s_fd,recv,sizeof(recv),0,(struct sockaddr*)&caddr,&len);
