#include<stdio.h>
int main()
{
	int a,b,x,y;
	while(scanf("%d%d",&a,&b)==2)
	{
		x=a;
		y=b;
		while(a!=b)
			if(a>b)
				a=a-b;
			else
				b=b-a;
		printf("%d\n",x/a*y);
	}
	return 0;
}
