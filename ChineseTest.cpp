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
		case 1:sprintf(ctmp,"һ"); break;
		case 2:sprintf(ctmp,"��"); break;
		case 3:sprintf(ctmp,"��"); break;
		case 4:sprintf(ctmp,"��"); break;
		case 5:sprintf(ctmp,"��"); break;
		case 6:sprintf(ctmp,"��"); break;
		case 0:sprintf(ctmp,"��"); break;
		default:printf("Error!\n"); 
	}
	printf("%d��֮������%s\n",n,ctmp);
	return 0;
}
