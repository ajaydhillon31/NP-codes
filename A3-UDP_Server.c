#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include<string.h>
int main()
{
char str[100];
int s_fd;
struct sockaddr_in saddr,caddr;
s_fd = socket(AF_INET, SOCK_DGRAM, 0);
bzero( &saddr, sizeof(saddr));
saddr.sin_family = AF_INET;
saddr.sin_addr.s_addr = htonl(INADDR_ANY);
saddr.sin_port = htons(43454);
bind(s_fd, (struct sockaddr *) &saddr, sizeof(saddr));

int len;
while(1)
{
bzero( str, 100);
int count=recvfrom(s_fd,str,sizeof(str),0,(struct sockaddr*)&caddr,&len);

printf("Echoing back - %s, %d",str,count);
count=sendto(s_fd,str,strlen(str),0,(struct sockaddr*)&caddr,sizeof(caddr));
printf("/n%d/n",count);

break;
}
}
