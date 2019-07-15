#include<stdio.h>
int main()
{
	int a,b,ans,i;
	while(scanf("%d %d",&a,&b)==2)
	{
		if(a==0&&b==0)
			break;
		ans=1;
		for(i=1;i<=b;++i)
		{
			ans=(ans*a)%1000;
		}
		printf("%d\n",ans);
	}
	return 0;
}
