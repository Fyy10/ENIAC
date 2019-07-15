#include<stdio.h>
#include<algorithm>
using namespace std;

struct node
{
	int father;
	int value[2];	//value[0]表示选这个结点的最大价值，value[1]表示不选这个结点的最大价值
	int son[6001];
	int p;
}people[6001];

int findroot(int x)
{
	return people[x].father=people[x].father==x?x:findroot(people[x].father);
}

void build(int x);

int main()
{
	int n,l,k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&people[i].value[0]);
		people[i].father=i;
		people[i].value[1]=-200;
		people[i].p=0;
	}
	while(scanf("%d %d",&l,&k)==2)
	{
		if(l==0&&k==0)
			break;
		people[l].father=k;
		people[k].son[people[k].p]=l;
		people[k].p++;
	}
	int rt=findroot(1);
	build(rt);
	printf("%d",max(people[rt].value[0],people[rt].value[1]));
	return 0;
}

void build(int x)
{
	if(people[x].p==0)
	{
		people[x].value[1]=0;
		return;
	}
	int sumchoose=0,sumnotchoose=0;
	for(int i=0;i<people[x].p;i++)
	{
		build(people[x].son[i]);
		sumchoose+=people[people[x].son[i]].value[0];
		sumnotchoose+=people[people[x].son[i]].value[1];
	}
	people[x].value[0]+=sumnotchoose;
	people[x].value[1]=max(sumchoose,sumnotchoose);
}
