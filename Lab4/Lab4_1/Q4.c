#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	pid_t p;
	int status;

	p = fork();

	//consider that fork function works correctly
	if(p < 0) //false to work
		return -1;

	else if(p == 0) {//child process
		printf("child process number: %d\n", getpid());

		printf("ls: \n");
		execl("/bin/ls", "ls", "-1", (char*) 0);
		perror("execl failed to run ls");
	}
	
	else {//parent process
		waitpid(p, &status, 0);
		printf("I'm parent process %d\n", getpid());
		printf("My child works perfectly!\n");
	}
}
