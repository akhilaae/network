#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main(){
	int x,sume=0,sumo=0,size=5;
	int arr[10];
	printf("enter values : ");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	x=fork();
	if (x==0){
		for(int i=0;i<size;i++){
			if(arr[i]%2!=0){
				sumo+=arr[i];
			}
		}
		printf("sum of odd = %d\n",sumo);
	}
	else if (x>0){
		for(int i=0;i<size;i++){
			if(arr[i]%2==0){
				sume+=arr[i];
			}
		}
		printf("sum of even = %d\n",sume);
	}
}