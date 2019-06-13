#include<stdio.h>
int main()
{
	int n,c[20],v[20],i,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&v[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
		v[i]-=c[i];
	}
	for(i=0;i<n;i++)
	{
		if(v[i]>0)
			ans+=v[i];
	}
	printf("%d",ans);
	return 0;
}
