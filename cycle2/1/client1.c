#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 2000

int main(int argc, char const* argv[])
{
	int status, valread, client_fd;
	struct sockaddr_in serv_addr;
	if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
		<= 0) {
		printf(
			"\nInvalid address/ Address not supported \n");
		return -1;
	}

	if ((status
		= connect(client_fd, (struct sockaddr*)&serv_addr,
				sizeof(serv_addr)))
		< 0) {
		printf("\nConnection Failed \n");
		return -1;
	}
	int flag=0;
    while (flag==0){
	char* hello[20];
	printf("Enter message : ");
	scanf("%s",hello);
	char buffer[1024] = { 0 };
	send(client_fd, hello, strlen(hello), 0);
	printf("Message sent\n");
	valread = read(client_fd, buffer,1024 - 1); 
	printf("Recieved : %s\n", buffer);
	printf("Do you wish to continue? : ");
    scanf("%d",&flag);
	}
	close(client_fd);
	return 0;
}
