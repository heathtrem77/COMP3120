#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	char reading[100];
	FILE* file_p;
	file_p = fopen("lab2.txt","w");
	fputs("Hello, my name is Heath Kim!", file_p);

	fclose(file_p);

	file_p = fopen("lab2.txt", "r");

	fgets(reading, 100, file_p);

	printf("lab2 : %s \n", reading);

	fclose(file_p);
	return 0;
}
