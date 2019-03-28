#include<stdio.h>
int main()
{
	int n,m,ans=0,judge=0;
	scanf("%d %d",&n,&m);
	if(m%n==0)
	{
		m/=n;
		while(m%3==0)
		{
			++ans;
			m/=3;
		}
		while(m%2==0)
		{
			++ans;
			m/=2;
		}
		if(m==1)
			judge=1;
	}
	if(judge)
		printf("%d\n",ans);
	else
		printf("%d\n",-1);
	return 0;
}
