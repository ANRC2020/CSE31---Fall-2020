#include<stdio.h>

int sum(int m, int n) {
	return m + n;
}

int main() {
	int m = 10, n = 5;
	
	int s = sum(m,n);
	
	printf("%d\n", s);
	return 0;
}
