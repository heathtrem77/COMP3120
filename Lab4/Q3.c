#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	int status;
	pid_t p;

	p = fork();

	//consider that fork function works correctly
	if(p < 0) //false to work
		return -1;

	else if(p == 0) {//child process
		printf("child process number: %d\n", getpid());
		printf("Hello\n");
	}
	
	else {//parent process
		waitpid(p, &status, 0);
		printf("I'm parent process %d\n", getpid());
		printf("goodbye\n");
	}
	return 0;
}

//We can use the function waitpid, instead of wait. Waitpid function makes parent process waiting until the certain child end.
