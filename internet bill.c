#include<stdio.h>
int main(void)
{
	//quiz no 1 question
	int gb;
	float bill, tot_bill=0,tax=0.1;
	printf("Enter the total no of GBs used: ");
	scanf("%d",&gb);
	if(gb<0)
	{
		printf("GBs can not be negative: ");
	}
	else if(gb<=100)
	{
		bill=gb*2;
	}
	else if(gb<=200)
	{
		bill=(100*2)+((gb-100)*1.5);
	}
	else if(gb<=400)
	{
		bill=(100*2)+(100*1.5)+((gb-200)*1);
	}
	else
	{
		bill=(100*2)+(100*1.5)+(200*1)+((gb-400)*0.5);
	}
	tot_bill=bill+(bill*tax);
	printf("\nYoy Total Bill is Rs: %.2f",tot_bill);
	return 0;
}