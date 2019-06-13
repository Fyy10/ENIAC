#include<stdio.h>
#include<string.h>
#define INF 1000000000
struct node
{
	int father;
	int val;
}set[100001];
int min1,min2,topa;
int lca(node set[],int u,int v);
int getdepth(node set[],int u);
int depth[100001]={0};
int main()
{
	int n,q,u,v,tmp;
	memset(set,-1,sizeof(set));
	scanf("%d %d",&n,&q);
	n-=1;
	while(n--)
	{
		scanf("%d %d %d",&u,&v,&tmp);
		if(set[u].father==-1)
		{
			set[u].father=v;
			set[u].val=tmp;
		}
		else
		{
			set[v].father=u;
			set[v].val=tmp;
		}
	}
	for(n=0;n<q;n++)
	{
		scanf("%d %d",&u,&v);
		min1=INF;
		min2=INF;
		topa=lca(set,u,v);
		if(min1==set[topa].val)
			printf("%d\n",min2);
		else
			printf("%d\n",min1);
	}
	return 0;
}
int lca(node set[],int u,int v)
{
	if(set[u].father>-1&&set[u].val<min1)
	{
		min2=min1;
		min1=set[u].val;
	}
	else
	{
		if(set[u].val<min2&&set[u].val>min1)
			min2=set[u].val;
	}
	if(set[v].father>-1&&set[v].val<min1)
	{
		min2=min1;
		min1=set[v].val;
	}
	else
	{
		if(set[v].val<min2&&set[v].val>min1)
			min2=set[v].val;
	}
	if(u==v)
		return u;
	else
	{
		if(getdepth(set,u)>getdepth(set,v))
			return lca(set,set[u].father,v);
		else
			return lca(set,u,set[v].father);
	}
}
int getdepth(node set[],int u)
{
	if(depth[u]>0)
		return depth[u];
	if(set[u].father==-1)
	{
		depth[u]=1;
		return depth[u];
	}
	else
	{
		depth[u]=getdepth(set,set[u].father)+1;
		return depth[u];
	}
}
