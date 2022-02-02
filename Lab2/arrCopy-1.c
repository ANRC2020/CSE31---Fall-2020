#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printArr(int *a, int size, char *name)
{
	
	printf("\n%s array contents: ", name);

	for(int i = 0; i < size; i++)
	{
		printf("%d ", *(a + i));
	}
}

int* arrCopy(int *a, int size)
{
	//int new[size];
	int *p = (int*)malloc(size * sizeof(int)); //&new[0];
	
	for(int i = 0; i < size; i++)
	{
		//printf("%d ", *(a + i));
		p[i] = *(a + i);
	}
	
	return p;
}

int main()
{    
	int n;
	int *arr;    
	int *arr_copy;
	int i;    
	printf("Enter the size of array: ");    
	scanf("%d", &n);    //n -> 5
	//Dynamically create an int array of n items    
	//arr[n];
	int orig[n];
	arr = &orig[0];
	//Ask user to input content of array
	for(i = 1; i < n + 1; i++)
	{
		printf("Enter array element #%d: ", i);
		scanf("%d", &(*(arr + i - 1)) );
	}
	
	/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	//Print original array    
	printArr(arr, n, "Original");
	//Copy array    
	arr_copy = arrCopy(arr, n);
	//Print new array    
	printArr(arr_copy, n, "Copied");    
	printf("\n");    
	return 0;
}


