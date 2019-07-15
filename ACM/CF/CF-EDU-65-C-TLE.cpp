#include<stdio.h>
struct user
{
	int father;
	int gnum;
}a[500001];
int k[500001];
int findroot(int x);
int main()
{
	int i,j,k1,n,m;
	for(i=1;i<=500001;i++)
	{
		a[i].father=-1;
		a[i].gnum=1;
	}
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&k1);
		if(k1>0)
		{
			scanf("%d",&k[1]);
			for(j=2;j<=k1;j++)
			{
				scanf("%d",&k[j]);
				int r1=findroot(k[j-1]),r2=findroot(k[j]);
				a[r2].father=r1;
				a[r1].gnum+=a[r2].gnum;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[findroot(i)].gnum);
	}
}
int findroot(int x)
{
	if(a[x].father==-1)
		return x;
	return findroot(a[x].father);
}
