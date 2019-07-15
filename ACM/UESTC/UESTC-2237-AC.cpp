#include<stdio.h>
int a[200001];
int pos[200001];
int main()
{
	int n,i,ans,tmp1,tmp2;
	while(scanf("%d",&n)==1)
	{
		ans=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			pos[a[i]]=i;
		}
		for(i=1;i<=n;i++)
		{
			if(pos[i]!=i)
			{
				tmp1=a[i];
				tmp2=pos[a[pos[i]]];
				a[i]=a[pos[i]];
				a[pos[i]]=tmp1;
				pos[a[pos[i]]]=pos[i];
				pos[i]=tmp2;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
