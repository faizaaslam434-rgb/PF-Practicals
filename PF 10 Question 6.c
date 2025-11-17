#include<stdio.h>
int main(void)
{
	printf("=================================================================================\n");
	printf("PROGRAM TO FILL THE ARRAY WITH THE SQUARE OF ITS INDEX AND PRINT IT USING POINTER:\n");
	printf("=================================================================================\n");
	int arr[10];
	int i;
	for(i=0; i<=10; i++)
	{
		arr[i]=i*i;
	}
	printf("printing array with square of its index:\n");
	printf("---------------------------------------\n");
	for(i=0; i<=10; i++)
	{
		printf("%d ",*(arr+i));
	}
	printf("\n");
	return 0;
}