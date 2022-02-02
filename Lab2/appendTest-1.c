#include <stdio.h>
#include <string.h>

/*    Return the result of appending the characters in s2 to s1.    
Assumption: enough space has been allocated for s1 to store the extra    
characters.*/

char* append(char s1[], char s2[], char arr[]) {    

	int s1len = strlen(s1);    
	int s2len = strlen(s2);    
	int k;    
	for (k = 0; k < (s1len+s2len); k++) {        
		if(k < s1len) {
			arr[k] = s1[k];
		} else {
			arr[k] = s2[k - s1len];
		}
	} 
	
	return arr;
}

int main() {    

	char str1[10];    
	char str2[10]; 
	   
	while(1) {        
		printf("str1 = ");        
		if (!gets(str1)) {            
			return 0;        
		};        
		printf("str2 = ");        
		if (!gets(str2)) {            
			return 0;        
		};        
		char arr[(strlen(str1) + strlen(str2))];
		printf ("The result of appending str2 to str1 is %s.\n", append(str1, str2, arr));
		
		for(int k = 0; k < (strlen(str1) + strlen(str2)); k++) {
		printf("%c", arr[k]);
		}
		printf("\n");   
	}
	   
	return 0;
}

