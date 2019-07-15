#include<stdio.h>
int main()
{
	int n,last2,sum,tmp1,tmp2,i;
	while(scanf("%d",&n)==1)
	{
		if(n==-1)
			break;
		last2=0;
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&tmp1,&tmp2);
			sum+=tmp1*(tmp2-last2);
			last2=tmp2;
		}
		printf("%d miles\n",sum);
	}
	return 0;
}
