#include <stdio.h>

int main()
{
int count;

printf("Enter the number of repetitions for the punishment phrase: ");
scanf("%d", &count);

if(count < 0) {
	printf("\nYou entered an invalid value for the number of repetitions!\n");
} else {
	int error;
	printf("\nEnter the repetition count when you wish to introduce a typo: ");
	scanf("%d", &error);
	if(error < 1){
		printf("\nInvalid line count for error message.\n");
		return 0;
	}	
	printf("\n");
	for(int i =0; i < count; i++){
		if(i != error -1) {
			printf("C programming language is the best!");
		} else {
			printf("C programmming lnguage is the bet!");
		}
	}
	printf("\n");
}


return 0;
}
