#include<stdio.h>

int main(void)
{
	printf("=============================================================\n");
	printf("PROGRAM TO PRINT SECOND HIGHEST NUMBER IN A FLOAT TYPE ARRAY:\n");
	printf("=============================================================\n");
	float arr[20];
	printf("Input Elements of an Array:\n");
	for(int i=0; i<20; i++)
	{
		printf("Elements at-[%d]: ",i+1);
		if(scanf("%f",&arr[i])!=1)
		{
			printf("Invalid input:\n");
			return 1;
		}
	}
	float highest=arr[0];
	float Shighest=arr[0];
	for(int i=0; i<20; i++)
	{
		if(arr[i]>highest)
		{
			Shighest=highest;
			highest=arr[i];
			
		}
		else if(arr[i]<highest && arr[i]>Shighest)
		{
			Shighest=arr[i];
		}
	}
	if(highest == Shighest)
	{
		printf("\nNo Distinch Second Highest number found(all number may be same)\n");
	}
	else
	{
		printf("\n==========================================\n");
		printf("----The Second Highest Number is = %.2f----",Shighest);
	}
	return 0;
}