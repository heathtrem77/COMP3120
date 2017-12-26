#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

int main() {
	struct tm* today;
	struct timeval t;

	gettimeofday(&t, NULL);
	today = localtime(&t.tv_sec);

	printf("year: %d\n", today->tm_year+1900);
	printf("month: %d\n", today->tm_mon+1);
	printf("day: %d\n", today->tm_mday);
	printf("hour: %d\n", today->tm_hour);
	printf("minute: %d\n", today->tm_min);
	printf("second: %d\n", today->tm_sec);

	return 0;
}

//This function's interval is under 1 second. Because this is accurate enough for human, so we can say this is enough.
