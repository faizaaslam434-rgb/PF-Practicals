#include<stdio.h>
struct Employee
{
	int id;
	char name[50];
	float salary;
};
int main(void)
{
	struct Employee e[3];
	int i;
	printf("PROGRAM TO STORE AND DISPLAY INFORMATION OF 3 EMPLOYEE:\n");
	printf("=======================================================\n\n");
	printf("Input Information:\n");
	for(i=0; i<3; i++)
	{
		printf("\nEmployee no:%d\n",i+1);
		printf("Enter ID: ");
		scanf("%d",&e[i].id);
		printf("Enter Name: ");
		scanf("%s",&e[i].name);
		printf("Enter Salary: ");
		scanf("%f",&e[i].salary);
	}
	printf("\nEMPLOYEE DETAIL\n");
	printf("===============\n");
	for(i=0; i<3; i++)
	{
		printf("\n\nEmployee No:%d",i+1);
		printf("\nID:%d",e[i].id);
		printf("\nName:%s",e[i].name);
		printf("\nSalary:%.2f",e[i].salary);
	}
	return 0;
}