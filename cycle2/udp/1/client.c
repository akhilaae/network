#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>

struct sockaddr_in addr;

void main() {
    char *ip = "127.0.0.1";
    int port = 5539;
    int sockfd;
    
    char buffer[1024];
    socklen_t addr_size;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("[-] Socket error");
        exit(1);
    }
    printf("UDP client socket created.\n");

    memset(&addr, '\0', sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    // func(sockfd);
    while(1){
    bzero(buffer, 1024);
    printf("Enter client message: ");
    scanf(" %[^\n]", buffer);
    if(strcmp(buffer,"exit")==0)
    {
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&addr, sizeof(addr));
        printf("UDP client socket exited.\n");
        exit(0);
    }
    // printf("(Client) Data to server: %s\n", buffer);

    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&addr, sizeof(addr));

    bzero(buffer, 1024);
    addr_size = sizeof(addr);
    recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&addr, &addr_size);
    printf("Message from server: %s\n", buffer);
    }
}
