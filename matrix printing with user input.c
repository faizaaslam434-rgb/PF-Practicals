#include<stdio.h>
int main()
{
	int rows,columns;
	printf("Enter no of Rows: ");
	scanf("%d",&rows);
	printf("Enter no of columns: ");
	scanf("%d",&columns);
	int m[rows][columns];
	printf("\n\nNow Enter the Values of desired Matrix: \n");
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			printf("Elements at position[%d][%d]is:",i+1,j+1);
			scanf("%d",&m[i][j]);
		}
	}
	printf("\nNow the desired matrix will look like:\n");
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	int r1,c1;
	printf("\nNow enter no of rows: ");
	scanf("%d",&r1);
	printf("Enter no pof columns: ");
	scanf("%d",&c1);
	int n[r1][c1];
	printf("\n\nNow Enter the Values of desired Matrix: \n");
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			printf("Elements at position[%d][%d]is:",i+1,j+1);
			scanf("%d",&n[i][j]);
		}
	}
	printf("\nNow the desired matrix will look like:\n");
	for(int i=0;i<r1;i++)
	{
		for(int j=0;j<c1;j++)
		{
			printf("%d ",n[i][j]);
		}
		printf("\n");
	}
	printf("\n\nThe multiplication of the above matrices will be:\n");
	int result[rows][c1];
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<c1;j++)
		{
			result[i][j]=0;
			for(int k=0;k<r1;k++)
			{
				result[i][j]+=m[i][k]*n[k][j];
			}
		}
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<c1;j++)
		{
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}
	return 0;
}