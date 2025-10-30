#include<stdio.h>
int main()
{
	int a[2][2];
	int b[2][2];
	int c[2][2];
	printf("Enter values of Matrix A(2x2):\n");
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("Elements at position[%d][%d]: ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	printf("\nThe Matrix A(2x2) will look like:\n");
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter values of Matrix B(2x2):\n");
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("Elements at position[%d][%d]: ",i+1,j+1);
			scanf("%d",&b[i][j]);
		}
	}
	printf("\nThe Matrix B(2x2) will look like:\n");
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("\n\nThe Addition of matrix A and Matrix B is:\n");
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	return 0;
 }