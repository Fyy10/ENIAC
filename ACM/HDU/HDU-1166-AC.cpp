#include<stdio.h>
struct node
{
	int left,right,sum;
}tree[300000];
int a[50001];
void build(int x,int left,int right);
void add(int x,int pos,int val);
void sub(int x,int pos,int val);
int query(int x,int left,int right);
int main()
{
	int t,n,m,i,j,k,l;
	char tmp[10];
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%d",&n);
		for(l=1;l<=n;l++)
		{
			scanf("%d",&a[l]);
		}
		build(1,1,n);
		getchar();
		printf("Case %d:\n",k);
		while(1)
		{
			scanf("%s",tmp);
			if(tmp[0]=='E')
				break;
			scanf("%d %d",&i,&j);
			getchar();
			switch(tmp[0])
			{
				case 'Q':printf("%d\n",query(1,i,j));break;
				case 'A':add(1,i,j);break;
				case 'S':sub(1,i,j);break;
				default:;
			}
		}
	}
	return 0;
}
void build(int x,int left,int right)
{
	tree[x].left=left;
	tree[x].right=right;
	if(left==right)
	{
		tree[x].sum=a[left];
		return;
	}
	int mid=(left+right)>>1;
	build(2*x,left,mid);
	build(2*x+1,mid+1,right);
	tree[x].sum=tree[2*x].sum+tree[2*x+1].sum;
}
void add(int x,int pos,int val)
{
	if(tree[x].left==tree[x].right)
	{
		tree[x].sum+=val;
		return;
	}
	int mid=(tree[x].left+tree[x].right)>>1;
	if(pos<=mid)
		add(2*x,pos,val);
	else
		add(2*x+1,pos,val);
	tree[x].sum=tree[2*x].sum+tree[2*x+1].sum;
}
void sub(int x,int pos,int val)
{
	if(tree[x].left==tree[x].right)
	{
		tree[x].sum-=val;
		return;
	}
	int mid=(tree[x].left+tree[x].right)>>1;
	if(pos<=mid)
		sub(2*x,pos,val);
	else
		sub(2*x+1,pos,val);
	tree[x].sum=tree[2*x].sum+tree[2*x+1].sum;
}
int query(int x,int left,int right)
{
	if(tree[x].left==left&&tree[x].right==right)
		return tree[x].sum;
	int mid=(tree[x].left+tree[x].right)>>1;
	if(right<=mid)
		return query(2*x,left,right);
	else
		if(left>mid)
			return query(2*x+1,left,right);
		else
			return query(2*x,left,mid)+query(2*x+1,mid+1,right);
}
