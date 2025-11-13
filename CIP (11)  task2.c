#include <stdio.h>
struct Student
{
	char name[50];
	int roll_no;
	float marks[3];
	float avg;
};
int main(void)
{
	struct Student s[5];
	int i,j, highestStudentIndex=0;
	float highestAvg=0.0, total;
	for(i=0; i<5; i++)
	{
		printf("============================\n");
		printf("---Student %d Information---\n",i+1);
		printf("=============================\n");
		printf("Name: ");
		scanf("%s",&s[i].name);
		printf("Roll No: ");
		scanf("%d",&s[i].roll_no);
		printf("\nStudent %d Subject Marks:\n",i+1);
		total=0.0;
		for(j=0; j<3; j++)
		{
			printf("Subject %d: ",j+1);
			scanf("%f",&s[i].marks[j]);
			total+=s[i].marks[j];
		}
		s[i].avg=total/3.0;
		if(s[i].avg>highestAvg)
		{
			highestAvg=s[i].avg;
			highestStudentIndex=i;
		}
	}
	printf("\nAVERAGE MARKS OF EACH STUDENTS:\n");
	printf("=================================\n");
	for(i=0; i<5; i++)
	{
		printf("\nSTUDENT %d:\n",i+1);
		printf("NAME:%s\n",s[i].name);
		printf("ROLL NO:%d\n",s[i].roll_no);
		printf("AVERAGE:%.2f\n",s[i].avg);
	}
	printf("\n\nHIGHEST AVEARGE OF STUDENT:\n\n");
	printf("NAME:%s\n",s[highestStudentIndex].name);
	printf("ROLL NO:%d\n",s[highestStudentIndex].roll_no);
	printf("AVERAGE:%.2f\n",s[highestStudentIndex].avg);
	
	return 0;
}
