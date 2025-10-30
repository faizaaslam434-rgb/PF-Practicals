#include<stdio.h>
int main(voiud)
{
	int i;
	float balance,amount;
	printf("Enter Balance Amount of Money: ");
	scanf("%f",&balance);
	printf("\n SIMPLE ATM SYSTEM: ");
	printf("\n\n1. Check Balance: ");
	printf("\n2. Withdraw Money: ");
	printf("\n3. Deposite Money: ");
	printf("\n\nEnter Your Choice: ");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
        	printf("Your BALANCE AMOUNT is: %.2f",balance);
       	break;
        case 2:
        	printf("Enter the Amount of Money to Withdraw: ");
        	scanf("%f",&amount);
        	if(amount>balance)
        	{
        		printf("Insuficient Balance");
			}
        	else
        	{
        		balance-=amount;
        		printf("With draw successfully\nNew Balance is Rs: %.2f",balance);
			}
		break;
		case 3:
			printf("Enter the Amount of Money to Deposite: ");
			scanf("%f",&amount);
			if(amount<=0)
			{
				printf("Invalid Amount: ");
			}
			else
			{
				balance+=amount;
				printf("Deposite Successfully:\nNew Balance is rs:%.2f",balance);
			}
		break;
		default:
			printf("INVALID MENU OPTION");
	}
	return 0;
}