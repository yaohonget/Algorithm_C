#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <string.h>

void doSwitch(int* a, int* b);

int main() {
	int inputs [] = {12, 45, 67, 7, 34, 6, 456, 3, 23, 73, 854, 45, 56};
	int inputsLength = sizeof(inputs) / sizeof(inputs[0]);
	for(int i = 0;i < inputsLength; i++) {
		printf("%d  ", inputs[i]);
	}
	printf("\n");

	//clock_t start, finish;
	//double duration;
	//start = clock(); 
	
	struct timeval stop, start;
	unsigned long duration;
	gettimeofday(&start, NULL);  
	
	//struct timespec start, end;	
	//clock_gettime(CLOCK_MONOTONIC, &start);
	
	for(int i = 1; i < inputsLength; i++) {
		for(int j = 0; j < (inputsLength - i); j++) {
			doSwitch(&inputs[j], &inputs[j + 1]);
		}
	}
	
	//finish = clock();
	//duration = (double)(finish - start) / CLOCKS_PER_SEC;  
   	//printf( "took %f\n", duration ); 

	gettimeofday(&stop, NULL);
	duration = 1000000 * (stop.tv_sec-start.tv_sec)+ stop.tv_usec-start.tv_usec;
	printf("took %ld us\n", duration);
	
	//clock_gettime(CLOCK_MONOTONIC, &end);
	//uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
	//printf("took %I64d\n", delta_us);

	for(int i = 0; i < inputsLength; i++) {
		printf("%d  ", inputs[i]);
	}

	//doSwitch(&a, &b);
	//printf("a = %d, b = %d \n", a, b);
	return 0;
}

void doSwitch(int* a, int* b) {
	if(*a < *b) {
		int temp = *b;
		*b = *a;
		*a = temp;
	}
}
