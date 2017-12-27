#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

int count = 0;
struct timeval start_p, end_p;
double work_t;
pthread_mutex_t lock;

void* thread_f() {
	pthread_mutex_lock(&lock);
	count = 0;
	gettimeofday(&start_p, NULL);
	while(count<1000000) {
		count = count+1;
		printf("current count: %d\n", count);
	}
	gettimeofday(&end_p, NULL);

	work_t = (double)(end_p.tv_sec)+(double)(end_p.tv_usec)/1000000-(double)(start_p.tv_sec)-(double)(start_p.tv_usec)/1000000;

	printf("Total working time: %f\n", work_t);
	pthread_mutex_unlock(&lock);
}

int main() {
	pthread_t thread[2];
	int t_check;
	int status;

	int i = 1;

	t_check = pthread_create(&thread[0], NULL, thread_f, NULL);

	if(t_check < 0) {
		perror("thread creating failed\n");
	}

	t_check = pthread_create(&thread[1], NULL, thread_f, NULL);

	if(t_check < 0) {
		perror("thread creating failed\n");
	}

	pthread_join(thread[0], (void**)&status);
	printf("return thread 0 %d\n", status);

	pthread_join(thread[1], (void**)&status);
	printf("return thread 1 %d\n", status);

	return 0;
}
