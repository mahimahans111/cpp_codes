#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <time.h>

#define MAXLINE 1024 
// Our Critical Section

int decidecood(char buffer[MAXLINE])
{
	int i = 0;
	int mx = 0;
	for(i=0;i<strlen(buffer);i+=5)
	{
		char subbuff[5];
		memcpy(subbuff, &buffer[i], 4);
		subbuff[4] = '\0';
		int x;
		sscanf(subbuff,"%d",&x);
		if(x > mx)
		{
			mx = x;
		}
	}
	printf("MAX: %d\n",mx);
	fflush(stdout);
	return mx;
}


int main()
{
	int n=0;
	int PORT,NextPORT;
	int token;
	srand(time(NULL));


	scanf("%d",&PORT);
	scanf("%d",&NextPORT);
	scanf("%d",&token);

	int sockfd; 
	char buffer[MAXLINE]; 
	struct sockaddr_in servaddr,clientaddr, prevaddr; 

	printf("=========================================NODE=========================================\n");
	// Creating socket file descriptor 
	
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { 
		perror("socket creation failed in client"); 
		exit(EXIT_FAILURE); 
	}

	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&clientaddr, 0, sizeof(clientaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_addr.s_addr = INADDR_ANY; 

	// Filling Client information
	clientaddr.sin_family = AF_INET; 
	clientaddr.sin_port = htons(NextPORT); 
	clientaddr.sin_addr.s_addr = INADDR_ANY; 
	
	// binding port to client
	if (bind(sockfd, (const struct sockaddr *)&servaddr, 
		sizeof(servaddr)) < 0 ) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	int len; 
	len=sizeof(servaddr);
	

	if(token == 1)
	{
		char content[1000];
    	snprintf(content,sizeof(content),"%d",PORT);
		if(sendto(sockfd, (const char *)content, strlen(content),
			0, (const struct sockaddr *) &clientaddr, 
			sizeof(clientaddr))<0)
		{
			perror("could not send");
		}
	}


	memset(&prevaddr, 0, sizeof(prevaddr));
	n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
		MSG_WAITALL, ( struct sockaddr *) &prevaddr, 
		&len); 


	if(n<0)
	{
		perror("Could not recieve");
		return 0;
	} 

	buffer[n]='\0';

	printf("Recieved Election Message: %s\n",buffer);
	fflush(stdout);

	if(token == 1)
	{
		int coord = decidecood(buffer);
		char content[1000];
		
		snprintf(content,sizeof(content),"Coordinator is %d",coord);
		printf("%s\n",content);
		fflush(stdout);
		if(sendto(sockfd, (const char *)content, strlen(content),
			0, (const struct sockaddr *) &clientaddr, 
			sizeof(clientaddr))<0)
		{
			perror("could not send");
		}
		
	}
	else
	{
		
		char content[1000];
		snprintf(content,sizeof(content),"%s %d",buffer,PORT);
		if(sendto(sockfd, (const char *)content, strlen(content),
			0, (const struct sockaddr *) &clientaddr, 
			sizeof(clientaddr))<0)
		{
			perror("could not send");
		}

		memset(&prevaddr, 0, sizeof(prevaddr));
		n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
			MSG_WAITALL, ( struct sockaddr *) &prevaddr, 
			&len); 
		buffer[n] = '\0';
		printf("%s\n",buffer);
		fflush(stdout);
		if(sendto(sockfd, (const char *)buffer, strlen(buffer),
			0, (const struct sockaddr *) &clientaddr, 
			sizeof(clientaddr))<0)
		{
			perror("could not send");
		}

	}
	
    close(sockfd); 
	
	return 0;
}