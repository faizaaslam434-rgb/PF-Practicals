#include<stdio.h>
#include<string.h>
int main(void)
{
	printf("PROGRAM TO TAKE TWO STRINGS INPUT FROM USER THEN CHECK IF BOTH STRING ARE EQUAL \nSHOW STRINGS ARE EQUAL IF BOTH ARE UNEQUAL THEN CHECK WHICH STRING IS GREATER\n\n");
	printf("==============================================================================\n");
	char str1[20], str2[20];
	int i, j, count1, count2, t=1;
	printf("Enter String 1: ");
	gets(str1);
	printf("Enter String 2: ");
	gets(str2);
	count1=strlen(str1);
	count2=strlen(str2);
	for(i=0; i<count1; i++)
	{
		if(str1[i]!=str2[i])
		{
			t=0;
			break;
		}
		for(j=0; j<count2; j++)
		{
			if(str1[j]!=str2[j])
			{
				t=0;
				break;
			}
		}
	}
	if(t)
	{
		printf("\n\nBoth Strings are equal:\n");
	}
	else
	{
		printf("\n\nBoth String are not equal:");
		int g=0;
		for(i=0; i<count1; i++)
		{
			if(str1[i]>str2[i])
			g=1;
		}
		if(g)
		{
			printf("\nString 1 is greater: ");
		}
		else
		{
			printf("\nStrng 2 is greater: ");
		}
	}
	return 0;
}