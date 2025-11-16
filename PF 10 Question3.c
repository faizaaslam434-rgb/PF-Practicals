#include<stdio.h>
int main(void)
{
	printf("==============================================\n");
	printf("PROGRAM TO PRINT SUM ALL THE ELEMENTS OF ARRAY USING POINTER:\n");
	printf("==============================================\n");
	int arr[100];
	int n, sum=0;
	printf("Enter total number of elements in array: ");
	scanf("%d",&n);
	printf("input elements:\n");
	for(int i=0; i<n; i++)
	{
		printf("Elements at-[%d]: ",i+1);
		scanf("%d",&arr[i]);
		sum+=*(arr+i);
	}
	printf("\nSum of  All Array element is = %d",sum);
	return 0;
}