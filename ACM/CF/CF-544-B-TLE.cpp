#include<stdio.h>
int main()
{
	int n,i,j,k,a[200000],ans=0;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		a[i]%=k;
	}
	for(i=0;i<n-1;++i)
	{
		if(a[i]==-1)
			continue;
		for(j=i+1;j<n;++j)
		{
			if(a[j]==-1)
				continue;
			if((a[i]+a[j])%k==0)
			{
				++ans;
				a[i]=-1;
				a[j]=-1;
				break;
			}
		}
	}
	printf("%d\n",ans*2);
	return 0;
}
