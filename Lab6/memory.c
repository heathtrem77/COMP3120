#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

char reading[100];
void* read_status() {
	int i=0;
	int VmPeak, VmSize, VmData, VmStk, VmExe;
	FILE* fp;

	fp = fopen("/proc/1/status", "r");

	while(i<18) {
		fgets(reading, 50, fp);
		i++;
	}
	puts(reading);
	
	fclose(fp);
}

int main() {
	int t_id;
	int status;
	pthread_t finder;

	t_id = pthread_create(&finder, NULL, read_status, NULL);
	if(t_id == -1) {
		printf("thread creation failed");
		return -1;
	}

	pthread_join(finder, (void**)&status);

	return 0;
}
