#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define port 43392

void main(){
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in address;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(port);
    address.sin_family = AF_INET;
    int len = sizeof(address);

    char filename[512];
    bzero(filename,512);
    printf("Enter the file name :");

    scanf("%s",filename);

    int con_status = connect(sockfd, (struct sockaddr*)&address, len);

    if(con_status<0){
        perror("connection failed");
        exit(0);
    }
    send(sockfd, filename, strlen(filename), 0);

    char output[2048];
    bzero(output, 2048);

    int byteRecieved = recv(sockfd, output, 2048, 0);

    // output[byteRecieved] = '\0';
    if(strcmp(output, "no") == 0){
        printf("file does not exist\n");
    }
    else{
        int i=0;
        FILE *f = fopen("download.txt","w");
        while(output[i] != '\0'){
            fputc(output[i], f);
            i++;
        }
	printf("%s",output);
        fclose(f);
    }
    close(sockfd);
}
