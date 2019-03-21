#include<stdio.h>
#include<string.h>
int main()
{
	char ctmp[3];
	int n,m;
	scanf("%d",&n);
	m=n%7;
	switch(m)
	{
		case 1:sprintf(ctmp,"一"); break;
		case 2:sprintf(ctmp,"二"); break;
		case 3:sprintf(ctmp,"三"); break;
		case 4:sprintf(ctmp,"四"); break;
		case 5:sprintf(ctmp,"五"); break;
		case 6:sprintf(ctmp,"六"); break;
		case 0:sprintf(ctmp,"日"); break;
		default:printf("Error!\n"); 
	}
	printf("%d天之后是周%s\n",n,ctmp);
	return 0;
}
