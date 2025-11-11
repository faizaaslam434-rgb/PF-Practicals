#include<stdio.h>
#include<string.h>
int main(void)
{
	printf("\nPROGRAM TO TAKE FIRST AND LAST NAME AS INPUT FROM USER THEN COMBINE BOTH AND PRINT THE FULL NAME BACKWARD:\n");
	printf("==========================================================================================================\n");
	char first[30], last[30], full_name[50];
	int i, j, count1, count2;
	printf("Enter your First name: ");
	gets(first);
	printf("Enter your Last name: ");
	gets(last);
	count1=strlen(first);
	count2=strlen(last);
	for( i=0; i<count1; i++)
	{
		full_name[i]=first[i];
	}
	for( j=0; j<count2; j++)
	{
		full_name[count1+j]=last[j];
	}
	printf("\n\nYour Full Name is: %s\n",full_name);
	printf("\nYour full name in backward is: ");
	int count3=strlen(full_name);
	for(i=count3; i>=0; i--)
	{
		printf("%c",full_name[i]);
	}
	return 0;
}