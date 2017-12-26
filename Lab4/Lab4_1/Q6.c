#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	int i, status;
	pid_t p[1];

	p[0] = fork();

	if(p[0] < 0) //false to work
		return -1;

	else if(p[0] == 0) {//child process
		printf("child process number: %d\n", getpid());
	}
	
	else {//parent process
		p[1] = fork();
		if(p[1] < 0)
			return -1;

		else if(p[1] == 0) {
			printf("child process number: %d\n", getpid());
		}
		else
			printf("I'm parent process %d\n", getpid());
		wait(&status);
	}
	return 0;
}
