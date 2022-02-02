#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 

int main() {

	int num;
	int *ptr;
	int **handle;
	
	num = 14;
	ptr = (int *)malloc(2 * sizeof(int));
	*ptr = num;
	handle = (int **)malloc(1 * sizeof(int *));
	*handle = ptr;
	
	printf("Memory address of ptr: %p \n", ptr);
	printf("Memory address of handle: %p \n", *handle);
	printf("Memory address of num: %p \n", &num);
	
	
	return 0;
} 

