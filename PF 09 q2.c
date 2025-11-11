#include<stdio.h>
void assignedPosition();

int main(void)
{
	printf("SALES FLOW RECRUIMENT PROCESS\n");
	printf("===============================\n");
	assignedPosition();
	return 0;
}
void assignedPosition()
{
	int marks, exp;
	printf("Enter your Marks: ");
	scanf("%d",&marks);
	printf("Enter your Experience: ");
	scanf("%d",&exp);
	if(marks==50)
	{
		printf("\nYou are selected for Trainee Engineer:");
	}
	else if(marks>=60 && exp>=1)
	{
		printf("\nYou are selected for Assistant Developer:");	
	}
	else
	{
		printf("\nYou are selected for Associate Developer:");
	}
}