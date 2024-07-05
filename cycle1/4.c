#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main(){
	int pid,num;
	printf("Enter number : ");
	scanf("%d",&num);
	pid=fork();
	if (pid==0){
		printf("inside child ---\n");
		printf("exiting child ---\n");
	}
	else if (pid>0){
		printf("inside parent ---\n");
		int flag=0;
		for(int i=2;i<=num/2;i++){
			if(num%i==0){
				flag=1;
				break;
			}
		}
		if(flag){
			printf("Non prime!!\n");
		}
		else{
			printf("Prime!!\n");
		}
		printf("exiting parent ---\n");
	}
}