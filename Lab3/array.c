
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int* bubbleSort(int arr[], int n){
    int temp, i = 0, j = 0;
    int *s_arr = (int*)malloc(n * sizeof(int));
    int *max;
	
    // Copy arr to s_arr
    for(i=0; i<n; i++) {     
    	s_arr[i] = arr[i];
    	//printf("s_arr at index %d stores: %d \n", i, *(s_arr + i));
    }

    // Actual sorting using array notations
    // Comment this when implementing pointer version.
    /*
    for (i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if(s_arr[j] > s_arr[j+1]){
                temp = s_arr[j+1];
                s_arr[j+1] = s_arr[j];
                s_arr[j] = temp;
            }
        }
    }
	*/
    // Actually sorting using pointer notations. i.e. you cannot use "[]"!
    // Your code goes here...

	for(i=0; i<n; i++) {
		max = s_arr;
		
		for(j = 0; j<n-i; j++) {
			
			if(*max > *(s_arr + j)) {
				int temp = *(s_arr + j);
				
				*(s_arr + j) = *max;
				*max = temp;
				max = (s_arr + j);
				
				continue;
			}
			
			if(*max <= *(s_arr + j)) {
				max = (s_arr + j);
				
				continue;
			}
			
		}
		
	}
	/*
	for(int k = 0; k < n; k++)
		printf("Element %d of array: %d \n", k, *(s_arr + k) );
	*/

    return s_arr;

}

void printArray(int arr[], int n){
    int i = 0;
    printf("[");
    for(i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

int bSearch(int *arr, int min, int max, int key){
    // Binary search function. arr is the array, key is the value to search for, a and b are the boundaries of arr to be searched within.
    // You must use pointer notations. i.e. no "[]"
    // Your code goes here:
	int mid = (max + min )/2;
	
	while(min != max)  {
		
		//printf("Current min: %d, max: %d, mid: %d \n", min, max, mid);
		
		if((min == mid && key != *(arr + mid)) || (max == mid && key != *(arr + mid))) {
			break;
		}
	
		if(key < *(arr + mid)) {
			max = mid;
			mid = (max + min )/2;
			continue;
		} 
		
		if (key > *(arr + mid)) {
			min = mid;
			mid = (max + min)/2;
			continue;
		}
		
		if(key == *(arr + mid)) {
			return mid;
		}	
	
	}	

	return -1; // Modify this to return an appropriate value!
}
 int main() {

    int i = 0, size = 0, key = 0, result = 0;
    int *array, *sorted;

    printf("How big is your array?  ");
    scanf("%d", &size);
    array = (int*)malloc(size * sizeof(int));

    for(i=0; i<size; i++){
        printf("Please enter array[%d]:  ", i);
        scanf("%d", &array[i]);
    }
    /*
    printf("Array before sorting: " );
    for(int k = 0; k < size; k++)
    	printf("%d ", *(array + k));
    printf("\n");
    */
    printf("Please wait while I sort your numbers...\n");
    sorted = bubbleSort(array, size);
    
    printf("Here is your original array:\n");
    printArray(array, size);
    
    printf("Here is your SORTED array: \n");
    printArray(sorted, size);
    
    printf("What number are you looking for? ");
    scanf("%d", &key);
    ///
    printf("OK, let me see if I can find a \"%d\" in the array...\n", key);
    result = bSearch(sorted, 0, size-1, key);
    if(result != -1)
        printf("Got it! A \"%d\" is at index %d.\n", key, result);
    else
        printf("I'm sorry, a \"%d\" cannot be found in the array.\n", key);
	//*/
	return 0;


}


