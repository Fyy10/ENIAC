#include<stdio.h>
int main()
{
	int n,i,rleft,yleft;
	char tmp;
	while(1)
	{
		scanf("%d",&n);
		getchar();
		if(n==0)
			break;
		rleft=7;
		yleft=7;
		for(i=1;i<=n;++i)
		{
			scanf("%c",&tmp);
			if(tmp=='Y')
				--yleft;
			if(tmp=='R')
				--rleft;
		}
		if(tmp=='B')
		{
			if(rleft>0)
				printf("Yellow\n");
			else
				printf("Red\n");
		}
		if(tmp=='L')
		{
			if(yleft>0)
				printf("Red\n");
			else
				printf("Yellow\n");
		}
	}
	return 0;
}
