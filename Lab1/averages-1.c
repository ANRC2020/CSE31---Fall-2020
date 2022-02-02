#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int sum_pos = 0;
	int sum_neg = 0;
	int num_pos = 0;
	int num_neg = 0;
	int new_num = 0;
	
	do {
		printf("Please enter an integer: ");
		scanf("%d",&new_num);
		if(new_num < 0) {
			sum_neg += new_num;
			num_neg += 1;
			//printf("%d", num_neg);
		} 
		if(new_num > 0) {
			sum_pos += new_num;
			num_pos += 1;
		}
	} while(new_num != 0);
	
	//printf("Number of positive integers: %d\n", num_pos);
	printf("\n");
	
	if(num_pos > 0) {
		int avg_pos = (sum_pos/num_pos);
		printf("Positive average: %d\n", avg_pos);
	} 
	if(num_neg > 0) {
		int avg_neg = (sum_neg/num_neg);
		printf("Negative average: %d\n", avg_neg);
	}
	
return 0;

}
	 
