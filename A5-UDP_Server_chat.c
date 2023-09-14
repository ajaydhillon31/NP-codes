#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
int main()
{
char send[100],recv[100];
int s_fd;
struct sockaddr_in saddr,caddr;
s_fd = socket(AF_INET, SOCK_DGRAM, 0);
bzero( &saddr, sizeof(saddr));
saddr.sin_family = AF_INET;
saddr.sin_addr.s_addr = htonl(INADDR_ANY);
saddr.sin_port = htons(26005);
if (bind(s_fd, (struct sockaddr *) &saddr, sizeof(saddr))<0)
{
printf("HELLO@");
}
int len=sizeof(caddr);
while(1)
{
bzero( recv, 100);
bzero( send, 100);
recvfrom(s_fd,recv,sizeof(recv),0,(struct sockaddr*)&caddr,&len);
if(strcmp(recv,"exit\n")==0)
{
break;
}
printf("%s",recv);
fgets(send,100,stdin);

if(( sendto(s_fd,send,strlen(send),0,(struct sockaddr*)&caddr,len) == 0))
 {
 printf("HELLO");
 }
printf("NOT HELLO");

if(strcmp(send,"exit\n")==0)
{
break;
}

}
}

//sendto(fd,sendmessage,sizeof(sendmessage),0,(struct sockaddr*)&saddr,sizeof(saddr));
