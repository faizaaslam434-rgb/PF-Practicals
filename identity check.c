#include<stdio.h>
int main(void)
{
	int isidentity=1;
	int r,c;
	int i,j;
	printf("In order to check the given matrix is identity or not first you have to enter equal no or rows and columns for that matrix:\n");
	printf("Enter no of rows: ");
	scanf("%d",&r);
	printf("enter no of columns: ");
	scanf("%d",&c);
	int x[r][c];
	if(r!=c)
	{
		printf("Since given matrix is not a square matrix therefore it will also not be an identity matrix:\n ");
	}
	else
	{
		printf("\nInput elements of matrix:\n");
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				printf("Elements at position[%d][%d]: ",i+1,j+1);
				scanf("%d",&x[i][j]);
			}
		}
		printf("\nThe matrix will look like:\n");
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				printf("%d ",x[i][j]);
			}
			printf("\n");
		}
		for(i=0; i<r; i++)
		{
			for(j=0; j<c; j++)
			{
				if(i==j && x[i][j]!=1)
				{
					isidentity=0;
					break;
				}
				else if(i!=j && x[i][j]!=0)
				{
					isidentity=0;
					break;
				}
			}
		}
		if(isidentity==1)
		{
			printf("\nThe given Matrix is an IDENTITY MATRIX:\n");
		}
		else
		{
			printf("\nThe given matrix is not an IDENTITY MATRIX:\n");
		}
	}
	return 0;
}