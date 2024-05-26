#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/ip.h>
#include<netinet/in.h>
#include<arpa/inet.h>
void main(int argc,char **argv)
{
	int sfd;
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	perror("socket");
	struct sockaddr_in server_id,client_id;
	server_id.sin_family=AF_INET;
	server_id.sin_port=htons(atoi(argv[1]));
	server_id.sin_addr.s_addr=inet_addr(argv[2]);
	int len=sizeof(server_id);
	bind(sfd,(struct sockaddr*)&server_id,len);
	perror("bind");
	while(1)
	{
	char s[20],p[20];
	recvfrom(sfd,s,sizeof(s),0,(struct sockaddr*)&client_id,&len);
	printf("data:%s\n",s);
	printf("enter data\n");
	scanf("%s",p);
	char *q;
	q=malloc(sizeof(s)+sizeof(p)+1);
	strcpy(q,p);
	strcat(q,s);
	sendto(sfd,q,strlen(q)+1,0,(struct sockaddr*)&client_id,len);
	
	}
}
