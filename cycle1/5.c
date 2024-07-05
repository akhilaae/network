#include <stdio.h>
#include <unistd.h>
void main(){
	for(int i=0;i<5;i++){
		sleep(1);
		printf("hello\n");
	}
}