#include<stdio.h>

void SortFunction(int *arr,int size,int order);
int main(void)
{
	printf("===========================================================================\n");
 	printf("PROGRAM THAT SORTS AN ARRAY IS ASCENDING PR DESCENDING ORDER USING FUNCTION:\n");
 	printf("===========================================================================\n");
	int size;
	int order;
	printf("Enter Size of Array: ");
	scanf("%d",&size);
	int arr[size];
	printf("Input Elements:\n");
	for(int i=0; i<size; i++)
	{
		printf("Elements at-[%d]: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter order in which you want to sort array:\n1.Ascending\n2.Descending\n");
	scanf("%d",&order);
	SortFunction(arr, size, order);
	printf("==============\n");
	printf("Sorted Array:\n");
	printf("==============\n");
	for(int i=0; i<size; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
void SortFunction(int *arr,int size,int order)
{
	int temp;
	if( order == 1)
	{
		for( int i=0; i<size-1; i++)
		{
			for( int j=i+1; j<size; j++)
			{
				if(arr[i]>arr[j])
				{
				    temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
	}
	else
	{
		for( int i=0; i<size-1; i++)
		{
			for( int j=i+1; j<size; j++)
			{
				if(arr[i]<arr[j])
				{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
	}
}