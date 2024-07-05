#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
void main(){
	char string[10];
	int fdw=open("file.txt", O_CREAT | O_RDWR, 0777);
	printf("enter string to be added : ");
	scanf("%s",string);
	int length=strlen(string);
	write(fdw,string,length);
	char buff[50];
	close(fdw);
	int fdr=open("file.txt", O_CREAT | O_RDWR, 0777);
	int size=read(fdr,buff,length);
	printf("%s",buff);
	close(fdr);
}