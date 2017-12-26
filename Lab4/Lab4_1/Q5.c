#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	int i, m, status;
	pid_t p;

	p = fork();

	//consider that fork function works correctly
	if(p < 0) //false to work
		return -1;

	else if(p == 0) {//child process
		printf("child process number: %d\n", getpid());
		for(i=0; i<10; i++) {
			m = i*(i+1);
			printf("Multiple %d\n", m);
		}
	}
	
	else {//parent process
		printf("I'm parent process %d\n", getpid());
		printf("Just wait, I'll sleep now\n\n");
		wait(&status);
		printf("OK! I woke up!\n");
	}
}

//Wait function returns an address of the ended child process.
