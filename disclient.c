// Client side implementation of UDP client-server model 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
  
#define PORT 3083
#define MAXLINE 1024 
  
// Driver code 
int main() { 
    int sockfd; 
    char buffer[MAXLINE]; 
    char *hello = "Client wants to know the current time"; 
    struct sockaddr_in sa; // Socket address data structure

    printf("\n");
    printf("***********CLIENT***********\n"); 
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {  // New socket creation and checking for valid socket
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&sa, 0, sizeof(sa)); 
      
    // Clearing and assigning type and address to the socket
    sa.sin_family = AF_INET; 
    sa.sin_port = htons(PORT); 
    sa.sin_addr.s_addr = INADDR_ANY; 
      
    int n, len; 

    // Sending the Data to the server
    sendto(sockfd, (const char *)hello, strlen(hello), 
        0, (const struct sockaddr *) &sa,  
            sizeof(sa)); 
    printf("Message Sent!.\n"); 

    // Recieving the response from the server
    n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
                MSG_WAITALL, (struct sockaddr *) &sa, 
                &len); 
    buffer[n] = '\0'; 
    // Printing the response recieved
    printf("Server : %s\n", buffer); 

    // Closing the Socket connection
    close(sockfd); 
    return 0; 
} 
