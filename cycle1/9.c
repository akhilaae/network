#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
void main(){
	int pid;
	pid=fork();
	if (pid==0){
		printf("inside child ---\n");
		printf("Process id of child = %d\n",getpid());
		printf("Process id of parent = %d\n",getppid());
		char buff[50];
		int fdr=open("sourcefile.txt", O_CREAT | O_RDWR, 0777);
		int size=read(fdr,buff,50);
		printf("Completed reading..\n");
		printf("%s",buff);
		printf("exiting child ---\n");
	}
	else if (pid>0){
		printf("inside parent ---\n");
		printf("exiting parent ---\n");
	}
}