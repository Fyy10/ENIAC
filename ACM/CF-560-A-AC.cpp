#include<stdio.h>
int main()
{
	int n,x,y,i,ans=0;
	int a[200001];
	scanf("%d %d %d",&n,&x,&y);
	for(i=0;i<n;i++)
	{
		scanf("%1d",&a[i]);
	}
	for(i=n-x;i<n;i++)
	{
		if(i==n-y-1)
		{
			if(!a[i])
				ans++;
		}
		else
		{
			if(a[i])
				ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
