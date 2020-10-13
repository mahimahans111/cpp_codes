// Server side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <stdbool.h>
#include <string.h> 
#include <sys/types.h> 
#include <sys/time.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <time.h>

// Port for server
#define PORT	 3000 

#define MAXLINE 1024 
#define SIZE 20

// Structure for storing clients address
struct Queue { 
    int front, rear, size; 
    unsigned capacity; 
    struct sockaddr_in* array; 
}; 
  
// function to create a queue 
// of given capacity. 
// It initializes size of queue as 0 
struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*)malloc( 
        sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0; 
  
    // This is important, see the enqueue 
    queue->rear = capacity - 1; 
    queue->array = (struct sockaddr_in*)malloc( 
        queue->capacity * sizeof(struct sockaddr_in)); 
    return queue; 
} 
  
// Queue is full when size becomes 
// equal to the capacity 
int isFull(struct Queue* queue) 
{ 
    return (queue->size == queue->capacity); 
} 
  
// Queue is empty when size is 0 
int isEmpty(struct Queue* queue) 
{ 
    return (queue->size == 0); 
} 
  
// Function to add an item to the queue. 
// It changes rear and size 
void enqueue(struct Queue* queue, struct sockaddr_in item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1) 
                  % queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    
} 
  
// Function to remove an item from queue. 
// It changes front and size 
struct sockaddr_in dequeue(struct Queue* queue) 
{ 
	struct sockaddr_in item;
	memset(&item, 0, sizeof(item));

    if (isEmpty(queue)) 
        return item; 
    item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) 
                   % queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 


// Driver code 
int main() { 
	int sockfd; 
	struct timeval tv;
	char buffer[MAXLINE]; 
	char str[100]; 
	time_t tick; 
	struct sockaddr_in servaddr, cliaddr; 
	
	printf("=========================================COORDINATOR=========================================\n"); 
	// Creating socket file descriptor 
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		perror("socket creation failed in server"); 
		exit(EXIT_FAILURE); 
	} 

	// Time interval after which recvfrom Timesout
	tv.tv_sec = 2;
	tv.tv_usec = 500000;

	// Setting timeout 
	if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,&tv,sizeof(tv)) < 0) {
    	perror("Could not set timeout");
	}
	
	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
	// Filling server information 
	servaddr.sin_family = AF_INET; // IPv4 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(PORT); 
	
	// Bind the socket with the server address 
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, 
		sizeof(servaddr)) < 0 ) 
	{ 
		perror("bind failed"); 
		exit(EXIT_FAILURE); 
	} 
	
	int len, n; 
	int k=1;
	// Queue for storing clients address
	struct Queue* resource = createQueue(20); 
	struct timeval time1, time2, tdiff1,tdiff2,curr_time,time_check;
	bool first=true;
	int total=2;

	len = sizeof(cliaddr); //len is value/resuslt 
	// Loop till we are getting connection

	
	while(1)
	{
		memset(&cliaddr, 0, sizeof(cliaddr));
		n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
			MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
			&len); 

		gettimeofday(&curr_time,NULL);
		// Just for the case when we get first recvfrom data
		if(first)
		{
			time1=time2=time_check=curr_time;
		}
		tdiff1.tv_sec= curr_time.tv_sec-time1.tv_sec;
		tdiff2.tv_sec= curr_time.tv_sec-time2.tv_sec;
 
 		// When the last data recieved or sent was 30 sec ago
 		// end the program
		if(curr_time.tv_sec-time_check.tv_sec>30)
			break;

		// checking if process using resource 1 is alive or dead
		// Making assumption that after one has taken a resource they
		// will relieve the resource withing 10 sec
		if(n<=0 && (tdiff1.tv_sec>10 || first))
		{
			cliaddr = dequeue(resource);
			first=false;
			k=1;
			total++;
		}
		// checking if process using resource 2 is alive or dead
		// Making assumption that after one has taken a resource they
		// will relieve the resource withing 10 sec
		else if(n<=0 && tdiff2.tv_sec>10)
		{
			cliaddr=dequeue(resource);
			k=2;
			total++;
		}
		else if(n>0 )
		{
			buffer[n] = '\0'; 
			
			// Checking if its an release or get request
			if(strcmp(buffer,"Resource")==0)
			{
				printf("Resource request from PORT: %d\n",ntohs(cliaddr.sin_port));
				enqueue(resource,cliaddr);
				gettimeofday(&time_check,NULL);
				buffer[0] = '\0';
			}
			else 
			{
				if(buffer[n-1]=='1')
					k=1;
				else
					k=2;
				cliaddr=dequeue(resource);
				gettimeofday(&time_check,NULL);
				total++;
			}
		}

		// If available resource is 0 the go back
		if(total==0)
			continue;
		total--;

		strcpy(str, "OK_");
		// char * appen;
		if(k==1)
			{
				strcat(str,"1");
				gettimeofday(&time1,NULL);
			}
		else
			{
				strcat(str,"2");
				gettimeofday(&time2,NULL);
			}
		
		// If invalid client address go back
		if(cliaddr.sin_port==0)
		{
		  	continue;
		}

		// read sys time 
		gettimeofday(&time_check,NULL);
		
		
		printf("Message from client: %s \n", buffer); 
		printf("Client Process PORT: %d\n",ntohs(cliaddr.sin_port));

		// Sending to client
		if(ntohs(cliaddr.sin_port)>0)
		if(sendto(sockfd, (const char *)str, strlen(str), 
			0, (const struct sockaddr *) &cliaddr,
			len)<0)
		{
			perror("could not send");
		}
		first=false;
		
	}

	return 0; 
} 
