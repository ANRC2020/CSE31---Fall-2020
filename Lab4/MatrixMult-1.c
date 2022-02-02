#include <stdio.h>
#include <malloc.h>

int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int **c = (int**)malloc(size * sizeof(int*));
	
	for(int i = 0; i < size; i++) {
		*(c + i) = (int*)malloc(size*sizeof(int));
	}
	
	int R = 0, C = 0, val = 0;
	
	while(C < size) {
		//printf("C value: %d\n", C);
		R = 0;
		while(R < size) {
			int tempC = C, tempR = R;
			for(int i = 0; i < size; i++) {
				int row = *(*(a + R) + i);
				int column = *(*(b + i) + C);
				//printf("row val: %d, col val: %d\n", row, column);
				val += (row*column);
			}
			*(*(c + tempR) + tempC) = val;
			val = 0;
			R++;
		}
		C++;
	}
	
	/*
	printf("The values stored in a:\n");
	for(int i = 0; i < size; i++) {
		printf(" %d", *(*(a + i)) );
	}
	printf("\n");
	for(int i = 0; i < size; i++) {
		printf(" %d", *(*(a + 0)+ i) );
	}
	printf("\n");
	*/
	return c;
}

void printArray(int **arr, int n){
	// (2) Implement your printArray function here
	for(int i = 0; i < n; i++) {
		int* ptr = *(arr + i);
		for(int j = 0; j < n; j++) {
			printf("%d ", *(ptr + j));
		}			
		printf("\n");
	}
	printf("\n");
}

int main() {
	int n = 4, v1 = 0, v2 = 0;
	int **matA, **matB, **matC;
	
	printf("Enter the dimension of the nxn array: ");
	scanf("%d", &n);
	
	// (1) Define 2 n x n arrays (matrices).
	
	matA = (int**)malloc(n*sizeof(int*));
	
	for(int i = 0; i < n; i++) {
		*(matA + i) = (int*)malloc(n*sizeof(int));
		int* ptr = *(matA + i);
		printf("For row %d:\n", (i + 1));
		for(int j = 0; j < n; j++) {
			printf("Enter the value: ");
			scanf("%d", &v1);
			*(ptr + j) = v1;
		}			
	}
	
	matB = (int**)malloc(n*sizeof(int*));
	
	for(int i = 0; i < n; i++) {
		*(matB + i) = (int*)malloc(n*sizeof(int));
		int* ptr = *(matB + i);
		printf("For row %d:\n", (i + 1));
		for(int j = 0; j < n; j++) {
			printf("Enter the value: ");
			scanf("%d", &v2);
			*(ptr + j) = v2;
		}			
	}

	// (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	
	printArray(matB, n);
	
	//(5) Call matMult to multiply the 2 arrays here.
	
	matC = matMult(matA, matB, n);
	
	//(6) Call printArray to print out resulting array here.
	
	printArray(matC, n);

    	return 0;
}
