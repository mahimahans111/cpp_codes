// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#include <time.h>
#include <errno.h> 


#define MAXLINE 1024 
  
// Driver code 
int main() { 
    int sockfd; 
    int PORTS[] = {3020,3010,3090}; // Specify the Server PORTS
    char buffer[MAXLINE]; 
    char str[1025];
    long int daemon_time; // To save the daemon Time
    char *hello = "Send Time!\n"; 
    struct sockaddr_in sa[3]; // Socket address data structure
    time_t tick; 
    int ctime[3]; // To save the Time of all the Nodes

    long int node_time;
    long int total=0;


    printf("\n");
    printf("*****NODE*****\n"); 

    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {  // New socket creation and checking for valid socket
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 

    // Initialising the Server Addresses
    memset(&sa[0], 0, sizeof(sa[0])); 
    memset(&sa[1], 0, sizeof(sa[1])); 
    memset(&sa[2], 0, sizeof(sa[2])); 
    
    // Clearing and assigning type and address to the socket
    for(int i = 0;i<3;++i)
    {
        sa[i].sin_family = AF_INET; 
        sa[i].sin_port = htons(PORTS[i]); 
        sa[i].sin_addr.s_addr = INADDR_ANY; 
    }
    

    int n;
    int len[3];
    len[0] = sizeof(sa[0]);
    len[1] = sizeof(sa[1]);
    len[2] = sizeof(sa[2]);



    // Find the Daemon Time to Synchonise the Clocks
    tick=time(NULL);
    total = (long int) tick;
    daemon_time=total;
    snprintf(str, sizeof(str), "Time %ld", daemon_time); 
    printf("\n%s",str);


    // Request Each Node for their Time to synchronise
    for(int i = 0;i<3;++i)
    {

        char buffer[MAXLINE];
        // Ask Nodes to send time
        sendto(sockfd, (const char *)hello, strlen(hello), 
        0, (const struct sockaddr *) &sa[i],
        len[i]); 

        // Wait for the Time
        int n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
        MSG_WAITALL, (struct sockaddr *) &sa[i], 
        &len[i]); 

        buffer[n] = '\0';
        printf("\nTime of node %i is :%s",i,buffer);
        ctime[i] = atol(buffer); 
        total+=ctime[i];
    }

    // Calculating Daemon Offset
    total = total/4;
    printf("\nDaemon offset: %ld",total - daemon_time);
    printf("\nTime of Daemon is :%ld\n",total);

    // Returning the Offset to each Node so that they can synchronise the clocks
    for(int i = 0;i<3;++i)
    {

        snprintf(buffer, sizeof(buffer), "%ld",total - ctime[i]); 
        sendto(sockfd, (const char *)buffer, strlen(buffer), 
                0, (const struct sockaddr *) &sa[i],
                len[i]); 
    }

    // Closing the Socket connection
    close(sockfd); 
    return 0; 
} 
