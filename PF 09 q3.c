#include<stdio.h>
 int volCal(int h, int a)
 {
 	float result;
 	result=(a*a*h)/3.0;
 	return result;
 }
 void getData()
 {
 	int h,a;
 	printf("Enter base value: ");
 	scanf("%d",&a);
 	printf("Enter height value: ");
 	scanf("%d",&h);
 	float volume=volCal(h,a);
 	printf("Volume is: %.2f",volume);
 }
 int main(void)
 {
 	getData();
 	return 0;
 }     
 
