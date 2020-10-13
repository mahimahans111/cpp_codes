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
// We are using two files as two resources for which 
// Clients are competing
void critical_section(int resource,int pid,int PORT)
{
	printf("Hello! %d is in Critical Section.",PORT);
    FILE *fp;
    char *filename;
    int random_wait=rand()%(6) + 1;
	sleep(random_wait);
    if(resource==1)
      	filename = "resource_one.txt";
    else
    	filename = "resource_two.txt";
    char content [1000];
    snprintf(content,sizeof(content),"Process %d is running on PORT %d\n",pid,PORT);
    fp = fopen(filename, "a");
    fprintf(fp, "%s\n", content);
   	fclose(fp);
}

void wait_for_child()
{
	int status=0;
	int pid=0;
	pid = wait(&status); 
	
	return ;
}


int main()
{
	int n=0;
	int PORT=2000;
	struct timeval tv;
	int server_PORT=3000;
	srand(time(NULL));

    // Setting the number of process to create
	int client_processes = 5;
 
	printf("Number of Client Processes %d\n",client_processes);
    
    // Creating client process using fork 
    // Each new process is assigned a PORT
	for(int i=0;i<client_processes;i++)
	{
		n=fork();

		if(n==0)
		{
			PORT=PORT+i+1;
			break;
		}

	}
	// We are not using the root client
	if(PORT==2000)
		{
			wait_for_child();
			return 0;
		}
	printf("[son] pid %d from [parent] pid %d port %d\n",getpid(),getppid(),PORT); 
	int sockfd; 
	char buffer[MAXLINE]; 
	char *request = "Resource";
	struct sockaddr_in	 servaddr,clientaddr; 

	printf("=========================================NODE=========================================\n");
	// Creating socket file descriptor 
	
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed in client"); 
		exit(EXIT_FAILURE); 
	}

    //Timeout Interval for recvfrom 
	tv.tv_sec = 5;
	tv.tv_usec = 500000;

	// Setting timeout 
	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,&tv,sizeof(tv)) < 0) {
    	perror("Could not set timeout");
	}

	memset(&servaddr, 0, sizeof(servaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_port = htons(server_PORT); 
	servaddr.sin_addr.s_addr = INADDR_ANY; 

	// Filling Client information
	clientaddr.sin_family = AF_INET; 
	clientaddr.sin_port = htons(PORT); 
	clientaddr.sin_addr.s_addr = INADDR_ANY; 
	
	// binding port to client
	if ( bind(sockfd, (const struct sockaddr *)&clientaddr, 
		sizeof(clientaddr)) < 0 ) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	int  len; 
	len=sizeof(servaddr);
	
	
	// Asking server for resource
	sendto(sockfd, (const char *)request, strlen(request),
			0, (const struct sockaddr *) &servaddr, 
			sizeof(servaddr));
	
	while(1)	
	{
		
		n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
				MSG_WAITALL, (struct sockaddr *) &servaddr, 
				&len);
		// if(n<0)
		// {
		// 	perror("Could not recieve");
		// } 
		if(n>0)
			{
				buffer[n] = '\0'; 
				break;
			}
		
	}
	
	// Checking the resource to which we have access
	printf("Message from Server : %s\n", buffer); 
	if(strcmp(buffer,"OK_1")==0)
		critical_section(1,getpid(),PORT);
	else if(strcmp(buffer,"OK_2")==0)
		critical_section(2,getpid(),PORT);

	char release[100]="DONE";

	
	strcat(release, buffer);
	// Releasing the resource
	if(sendto(sockfd, (const char *)release, strlen(release),
			0, (const struct sockaddr *) &servaddr, 
			sizeof(servaddr))<0)
		{
			perror("could not send");
		}
	
    // Close the socket
    close(sockfd); 
    wait_for_child();
	
	return 0;
	

}