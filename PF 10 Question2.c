#include<stdio.h>
void swapped(int *aptr, int *bptr, int *cptr)
{
	int temp=*bptr;
	*bptr=*aptr;
	*aptr=*cptr;
	*cptr=temp;      

}
int main()
{
	printf("==========================\n");
	printf("PROGRAM TO SWAP 3 NUMBERS\n");
	printf("==========================\n");
	int num1,num2,num3;
	num1=2;
	num2=3;
	num3=4;
	printf("---The numbers Before Swap:---\na=%d\nb=%d\nc=%d\n",num1,num2,num3);
	swapped(&num1, &num2, &num3);
	printf("---The numbers After Swap:---\na=%d\nb=%d\nc=%d\n",num1,num2,num3);
	return 0;
}