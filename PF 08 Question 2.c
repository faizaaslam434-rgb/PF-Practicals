#include<stdio.h>
#include<string.h>
int main(void)
{
	printf("\nPROGRAM TO FIND THE MAXIMUM OCCURENCE OF CHARATERS IN NAME AND COURSE NAME:\n");
	printf("==========================================================================\n\n");
	char str1[30], str2[30], maxChar1, maxChar2;
	int i, j, count1, count2, maxCount1=0, maxCount2;
	printf("Enter Your Name: ");
	gets(str1);
//	printf("Enter Your Course Name: ");
//	gets(str2);
	int len1=strlen(str1);
//	int len2=strlen(str2);
	for(i=0; i<len1; i++)
	{
		count1=0;
		for(j=0; j<len1; j++)
		{
			if(str1[i] == str1[j])
			{
				count1++;
			}
		}
		if(maxCount1<count1)
		{
			maxCount1=count1;
			maxChar1=str1[i];
		}
	//}
	printf("\nThe Maximum Occurence of Charaters in name is '%c'= %d times\n",maxChar1,maxCount1);
}
/*	for(i=0; i<len2; i++)
	{
		count2=0;
		for(j=0; j<len2; j++)
		{
			if(str2[i] == str2[j])
			{
				count2++;
			}
		}
		if(maxCount2<count2)
		{
			maxCount2=count2;
			maxChar2=str2[i];
		}
	}
	printf("\nThe Maximum Occurence of Character in Course name is '%c'= %d times\n",maxChar2,maxCount2);*/
	return 0;
}