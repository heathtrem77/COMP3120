#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	int i, status;
	pid_t p[1];
	char data[200];
	int pipe1[2];

	pipe(pipe1) == -1;

	p[0] = fork();

	if(p[0] < 0) //false to work
		return -1;

	else if(p[0] == 0) {//child process
		printf("child process number: %d\n", getpid());
		printf("child %d: OK! I sended my letter!\n\n", getpid());
		write(pipe1[1], "This is for my brother!", sizeof(data));
	}
	
	else {//parent process
		p[1] = fork();
		if(p[1] < 0)
			return -1;

		else if(p[1] == 0) {
			waitpid(p[0], &status, 0);
			read(pipe1[0], data, sizeof(data));
			printf("child process number: %d\n", getpid());
			printf("child %d: I Received letter (%s) \n\n", getpid(), data);
		}
		else
			printf("I'm parent process %d\n", getpid());
	}
	return 0;
}
