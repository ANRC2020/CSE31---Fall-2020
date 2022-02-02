#include <stdio.h>

int main(){
	int i;
	int four_ints[4];
	char* four_c;

	for(i = 0; i < 4; i++)
        four_ints[i] = 2;

	printf("%x\n", four_ints[0]);// 2
	
    four_c = (char*)four_ints;   

	for(i = 0; i < 4; i++)
        four_c[i] = 'A'; // ASCII value of 'A' is 65 or 0x41 in Hex.
    
    // Add your code for the exercises here:
    	printf("%x\n", four_ints[0]);// 41414141 
    	
    	printf("%x\n", four_ints[1]);// 2
    	
    	for(i = 0; i < 4; i++)
    		printf("four_c: %x\n", *(four_c + i) ); //41 once per iteration
    		
    	for(i = 0; i < 4; i++)
    		printf("four_int: %x\n", four_ints[i]);
    		
    	printf("Addresses: \n");
    	for(i = 0; i < 4; i++)
    		printf("four_int: %p\n", &four_ints[i]);
    		
    	for(i = 0; i < 4; i++)
    		printf("four_c: %p\n", (four_c + i) );
		
	return 0;
}
