#include"header.h"
void main(int argc,char **argv)
{
	int sfd;
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	perror("socket");
	struct sockaddr_in server_id;
	server_id.sin_family=AF_INET;
	server_id.sin_port=htons(atoi(argv[1]));
	server_id.sin_addr.s_addr=inet_addr(argv[2]);
	int len=sizeof(server_id);
	while(1)
	{
		char s[20];
	printf("enter data\n");
	scanf("%s",s);
	sendto(sfd,s,strlen(s)+1,0,(struct sockaddr*)&server_id,len);
	recvfrom(sfd,s,sizeof(s)+1,0,(struct sockaddr*)&server_id,&len);
	printf("new data:%s\n",s);
	}
}
