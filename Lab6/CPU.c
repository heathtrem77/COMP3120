#include <stdio.h>
#include <stdlib.h>

int main() {
	int utime,stime,t_time;
	FILE* fp;

	fp = fopen("/proc/1/stat", "r");
	fscanf(fp, "%*d %*s %*s %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %d %d",&utime,&stime);
	fclose(fp);

	t_time = utime + stime;

	printf("PID number 1's utime = %d, stime = %d\n", utime, stime);
	printf("total time = %d\n", t_time);
	printf("total time in milisecond = %d\n", (100 * t_time));

	return 0;
}
