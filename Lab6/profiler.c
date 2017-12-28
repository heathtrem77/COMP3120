#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

char reading[100];
void* read_status() {
	int i=0;
	int VmPeak, VmSize, VmData, VmStk, VmExe;
	FILE* fp;

	fp = fopen("/proc/1/status", "r");

	while(i<100) {
		fgets(reading, 100, fp);
		if(i == 17) {
			printf("\nPID number 1's status file ");
			puts(reading);
		}
		i++;
	}
	
	fclose(fp);
}

int main() {
	int i, tmp;
	int t_id;
	int status;
	pthread_t finder;
	int utime,stime,t_time;
	FILE* fp;

	//read stat
	fp = fopen("/proc/1/stat", "r");
	fscanf(fp, "%*d %*s %*s %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %d %d",&utime,&stime);

	fclose(fp);

	t_time = utime + stime;

	printf("PID number 1's utime = %d, stime = %d\n", utime, stime);
	printf("total time = %d\n", t_time);
	printf("total time in milisecond = %d\n", (100 * t_time));

	//read status
	t_id = pthread_create(&finder, NULL, read_status, NULL);
	if(t_id == -1) {
		printf("thread creation failed");
		return -1;
	}

	pthread_join(finder, (void**)&status);

	return 0;
}
