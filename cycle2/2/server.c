#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t mutex;
int clients[3];
int n=0;

void sendtoall(char *msg,int curr){
	int i;
	pthread_mutex_lock(&mutex);
	for(i=0;i<n;i++){
		if (clients[i]!=curr){
			if (send(clients[i],msg,strlen(msg),0)<0){
				printf("Sending failure\n");
				continue;
			}
		}
	}
	pthread_mutex_unlock(&mutex);
}
void *recvmg(void *client_sock){
	int sock=*((int *)client_sock);
	char msg[500];
	int len;
	while ((len=recv(sock,msg,20,0))>0){
		msg[len]='\0';
		sendtoall(msg,sock);
	}
}

int main(){
	struct sockaddr_in ServerIp;
	pthread_t recvt;
	int sock=0,client_sock=0;
	ServerIp.sin_family=AF_INET;
	ServerIp.sin_port=htons(52000);
	ServerIp.sin_addr.s_addr=inet_addr("127.0.0.1");
	sock=socket(AF_INET,SOCK_STREAM,0);
	if (bind(sock,(struct sockaddr *)&ServerIp,sizeof(ServerIp))<0){
		printf("Cannot bind! error\n");
	}
	else{
		printf("Server started\n");
	}
	if (listen(sock,3)<0){
		printf("Listening failed\n");
	}
	while(1){
		if((client_sock=accept(sock,(struct sockaddr *)NULL,NULL))<0){
			printf("accept failed\n");
		}else{
			perror("client accepted");
		}
		pthread_mutex_lock(&mutex);
		clients[n]=client_sock;
		n++;
		pthread_create(&recvt,NULL,(void *)recvmg,&client_sock);
		pthread_mutex_unlock(&mutex);
	}
	close(sock);
}