#include<stdio.h>
int main(void)
{
	int degree;
	char subfield;
	printf("YOU HAVE TWO MAJORS:\nELECTRICAL ENGINEERING\nCOMPUTER SCIENCE\n\ta.AI\n\tb.DS\n\tc.CS");
	printf("\n Press 1 if your degree is ELECTRICAL Pess 2 if your degree is COMPUTER SCIENCE\n");
	scanf("%d",&degree);
	printf("\nPress a for AI\nPress b for DS\nPress c for CS\n");
	scanf("%c",&subfield);
	switch(degree)
	{
		case 1:
			printf("Your degree is ELECTRICAL ENGINEERING");
			break;
		case 2:
			{
				printf("Your degree is COMPUTER SCEINCE\nWhich sub field you want to specialize?\n?");
				//printf("\nPress a for AI\nPress b for DS\nPress c for CS\n");
				scanf("%c",&subfield);
				switch(subfield)
				{
					case 'a':
						printf("\nARTIFICIAL INTELLIGENCE");
						break;
					case 'b':
						printf("\nDATA SCIENCE");
						break;
					case 'c':
						printf("\nCYBER SECURITY"); 
						break;
					default:
						printf("\nINVALID SUBFIELD");
						break;
				}
				break;
			}
			default:
				printf("INVALID DEGREE");
			break;	
	}
	return 0;
}