#include <stdio.h>

int main()
{
int x = 2, y = 3, *px = &x, *py = &y;
int arr[5] = {1,2,3,4,5};
printf("Value stored at x = %d and address is &x = %p", x, &x);
printf("\n");
printf("Value stored at *px = %d and address is *px = %p \n", *px , px);
printf("\n");
printf("Value stored at y = %d and address is &y = %p \n", y, &y);
printf("\n");
printf("Value stored at *py = %d and address is *py = %p \n", *py, py);
printf("\n");

for(int i = 0; i < 5; i++){
printf("Value stored at arr index %d = %d \n", i, *(arr + i) );
printf("\n");
}
printf("arr[0] = %d and *arr = %d\n", arr[0], *arr);

printf("*arr = %p", &arr);
return 0;
}

