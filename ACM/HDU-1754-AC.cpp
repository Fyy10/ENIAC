#include<stdio.h>
struct node
{
	int left,right;
	int max;
}tree[1000000];
int score[1000000];
void build(int n,int l,int r);
void upd(int n,int pos,int val);
int query(int n,int left,int right);
int maxn(int a,int b);
int main()
{
	int n,m,a,b,i;
	char tmp;
	while(scanf("%d %d",&n,&m)==2)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&score[i]);
		}
		getchar();
		build(1,1,n);
		while(m--)
		{
			tmp=getchar();
			scanf("%d %d",&a,&b);
			getchar();
			switch(tmp)
			{
				case 'Q':printf("%d\n",query(1,a,b));break;
				case 'U':upd(1,a,b);break;
				default:;
			}
		}
	}
	return 0;
}
void build(int n,int l,int r)
{
	tree[n].left=l;
	tree[n].right=r;
	if(l==r)
	{
		tree[n].max=score[l];
		return;
	}
	int mid=(l+r)>>1;
	build(2*n,l,mid);
	build(2*n+1,mid+1,r);
	tree[n].max=maxn(tree[2*n].max,tree[2*n+1].max);
}
void upd(int n,int pos,int val)
{
	if(tree[n].left==tree[n].right)
	{
		tree[n].max=val;
		return;
	}
	int mid=(tree[n].left+tree[n].right)>>1;
	if(pos<=mid)
		upd(2*n,pos,val);
	else
		upd(2*n+1,pos,val);
	tree[n].max=maxn(tree[2*n].max,tree[2*n+1].max);
}
int query(int n,int left,int right)
{
	if(tree[n].left==left&&tree[n].right==right)
		return tree[n].max;
	int mid=(tree[n].left+tree[n].right)>>1;
	if(right<=mid)
		return query(2*n,left,right);
	else
		if(left>mid)
			return query(2*n+1,left,right);
		else
			return maxn(query(2*n,left,mid),query(2*n+1,mid+1,right));
}
int maxn(int a,int b)
{
	return a>b?a:b;
}
