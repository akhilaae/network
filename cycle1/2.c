#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main(){
	int pid;
	pid=fork();
	if (pid==0){
		printf("inside child ---\n");
		printf("CHILD\n");
		printf("exiting child ---\n");
	}
	else if (pid>0){
		printf("inside parent ---\n");
		printf("PARENT\n");
		printf("exiting parent ---\n");
	}
}