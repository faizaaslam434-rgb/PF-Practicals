#include<stdio.h>
int main(void)
{
	int a,b,c,d;
	printf("INPUT THREE NUMBERS IN ORDER TO CHECK THE GREATEST NUMBER");
	printf("\n\nEnter 1st number: ");
	scanf("%d",&a);
	printf("Enter 2nd number: ");
	scanf("%d",&b);
	printf("Enter 3rd number: ");
	scanf("%d",&c);
	if(a>b)
	{
		d=a;
	}
	else
	{
		d=b;
	}
	if(d>c)
	{
		printf("\nThe greatest number is: %d",d);
	}
	else
	{
		printf("\nThe greatest number is: %d",c);
	}
	return 0;
}