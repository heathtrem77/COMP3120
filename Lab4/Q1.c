#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int x;
	pid_t p;

	x = 100;
	p = fork();

	//consider that fork function works correctly
	if(p < 0) //false to work
		return -1;

	else if(p == 0) {//child process
		printf("child process number: %d\n", getpid());
		printf("My x value: %d\n", x);
	}
	
	else {//parent process
		printf("I'm parent process %d\n", getpid());
		printf("My x value: %d\n", x);
	}
}

//If parent and child try to change the value of x at the same time, it won't work correctly. Because their instructions work simultaneously, so one of result can be ignored or overwritten.
