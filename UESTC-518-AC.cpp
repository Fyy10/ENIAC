#include<stdio.h>
int main()
{
	int a,b,c,t,i;
	scanf("%d",&t);
	for(i=1;i<=t;++i)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a+b==9)
			if(c==9)
				printf("Yes\n");
			else
				printf("No\n");
		else
			if(a+b==c)
				printf("No\n");
			else
				printf("Yes\n");
	}
	return 0;
}
