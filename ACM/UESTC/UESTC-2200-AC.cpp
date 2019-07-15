#include<stdio.h>
int main()
{
	int n,i,j,sum,tmp,t=0;
	while(scanf("%d",&n)==1)
	{
		t++;
		if(n==0)
			break;
		sum=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				scanf("%d",&tmp);
				if(i==1||i==n)
					sum+=tmp;
				else
				{
					if(j==1||j==i)
						sum+=tmp;
				}
			}
		}
		printf("Case #%d:%d\n",t,sum);
	}
	return 0;
}
