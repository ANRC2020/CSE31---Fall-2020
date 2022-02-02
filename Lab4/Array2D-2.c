#include <stdio.h>
#include <malloc.h>

void printArray(int**, int);

int main(){
	int i = 0, j = 0, n = 5;
	int **arr = (int**)malloc(n * sizeof(int*)); 

	// (3) Add your code to complete allocating and initializing the 2-D array here. The content should be all 0.
	for(i = 0; i < n; i++) {
		*(arr + i) = (int*)malloc(n * sizeof(int));
		int *ptr = *(arr + i);
		for(j = 0; j < n; j++) {
 			*(ptr + j) = 0;
		} 
	}
		


    // This will print our your array
	printArray(arr, n);

    // (6) Add your code to make arr a diagonal matrix
    for(i = 0; i < n; i++) {
		*(arr + i) = (int*)malloc(n * sizeof(int));
		int *ptr = *(arr + i);
		for(j = 0; j < n; j++) {
			if(j == i) {
				*(ptr + j) = j + 1;
				continue;
			}
 			*(ptr + j) = 0;
		} 
	}
	
	
	// (7) All printArray to print array
    printArray(arr, n);

	return 0;
}

void printArray(int ** array, int size){
    // (5) Implement your printArr here:
	for(int i = 0; i < size; i++) {
		int *ptr = *(array + i);
		for(int j = 0; j < size; j++) {
 			printf("%d ", *(ptr + j));
		} 
		printf("\n");
	}
	printf("\n");
}
