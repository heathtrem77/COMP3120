#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
	int fo, foc, fop;
	int i;
	char* reading;
	char writing[] = "Test for Q2\n";
	pid_t p;

	fo = open("File for opening", O_WRONLY|O_CREAT, 0644);
	if(fo < 0)
		return -1;

	p = fork();

	//consider that fork function works correctly
	if(p < 0) //false to work
		return -1;

	else if(p == 0) {//child process
		printf("child process number: %d\n", getpid());
		if(write(fo, writing, strlen(writing)) == -1)
			printf("write error!");

		foc = open("File for opening", O_RDONLY);
		if(foc < 0)
			return -1;

		reading = (char*)malloc(sizeof(char)*200);

		read(foc, reading, sizeof(reading));

		printf("Child's File contents: %s \n", reading);
		free(reading);
		close(foc);
	}
	
	else {//parent process
		printf("I'm parent process %d\n", getpid());

		if(write(fo, writing, strlen(writing)) == -1)
			printf("write error!");

		fop = open("File for opening", O_RDONLY);
		if(fop < 0)
			return -1;

		reading = (char*)malloc(sizeof(char)*200);

		read(fop, reading, sizeof(reading));

		printf("Parent's File contents: %s \n", reading);
		free(reading);
		close(fop);
	}
	close(fo);
	return 0;
}
