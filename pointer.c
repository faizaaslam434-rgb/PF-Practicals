#include<stdio.h>
int main()
{
	int x=20;
	int *xptr;
	xptr=&x;
	printf("Stored number is : %d\n",x);
	printf("Now print the stored number using pointer variable:%d\n",*xptr);
	printf("Now print the address of stored number using pointer:%p\n",(void *)xptr);
	//printf("Now print the address of stored number using pointer:%p\n",xptr);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
/*	int y=10;
	int *yptr;
	//*yptr=&y;
	yptr=&y;
	printf("%d\n",y);
	printf("address: %p\n",(void *)yptr);
	//printf("address: %p\n",yptr);
	printf("number: %d",*yptr);   */
	return 0;
}
