#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
void main(){
	char buff[50];
	int fdr=open("sourcefile.txt", O_CREAT | O_RDWR, 0777);
	int size=read(fdr,buff,50);
	printf("Completed reading..\n");
	close(fdr);
	int fdw=open("destinationfile.txt", O_CREAT | O_RDWR, 0777);
	write(fdw,buff,size);
	printf("Completed copying..\n");
	printf("size written : %d\n",size);
	close(fdw);
}