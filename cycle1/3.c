#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
void main(){
	int x;
	char string[20];
	printf("enter string : ");
	scanf("%s",string);
	x=fork();
	if (x==0){
		printf("In child process..\n");
		for(int i=0;i<strlen(string);i++){
			if(string[i]>=97)
				string[i]-=32;
		}
		printf("After conversion : %s\n",string);
		printf("Exiting child process..\n");
	}
	else if (x>0){
		printf("In parent process..\n");
		printf("Exiting parent process..\n");
	}
}