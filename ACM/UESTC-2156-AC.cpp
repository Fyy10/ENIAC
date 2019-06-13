#include<stdio.h>
#define LL long long
struct node
{
	int left,right;
	LL sum,mark,max,min;
}tree[5000000];
LL maxn(LL a,LL b);
LL minn(LL a,LL b);
void build(int x,int left,int right);
void update(int x,int left,int right,int val);
void pushdown(int x);
void pushup(int x);
long long findsum(int x,int left,int right);
LL findmax(int x,int left,int right);
LL findmin(int x,int left,int right);
int main()
{
	int n,q,l,r,k,tmp;
	scanf("%d %d",&n,&q);
	build(1,1,n);
	while(q--)
	{
		scanf("%d",&tmp);
		switch(tmp)
		{
			case 1:
				{
					scanf("%d %d %d",&l,&r,&k);
					update(1,l,r,k);
					break;
				}
			case 2:
				{
					scanf("%d %d",&l,&r);
					printf("%lld\n",findsum(1,l,r));
					break;
				}
			case 3:
				{
					scanf("%d %d",&l,&r);
					printf("%lld\n",findmax(1,l,r)-findmin(1,l,r));
					break;
				}
			default:;
		}
	}
	return 0;
}
LL maxn(LL a,LL b)
{
	return a>b?a:b;
}
LL minn(LL a,LL b)
{
	return a<b?a:b;
}
void build(int x,int left,int right)
{
	tree[x].left=left;
	tree[x].right=right;
	if(left==right)
	{
		tree[x].sum=(LL)0;
		tree[x].max=(LL)0;
		tree[x].min=(LL)0;
		tree[x].mark=(LL)0;
		return;
	}
	int mid=(left+right)>>1;
	build(x<<1,left,mid);
	build(x<<1|1,mid+1,right);
	tree[x].sum=(LL)0;
	tree[x].mark=(LL)0;
}
void update(int x,int left,int right,int val)
{
	if(tree[x].left==left&&tree[x].right==right)
	{
		tree[x].mark+=(LL)val;
		tree[x].max+=(LL)val;
		tree[x].min+=(LL)val;
		tree[x].sum+=((LL)val)*(right-left+1);
		return;
	}
	if(tree[x].mark)
		pushdown(x);
	int mid=(tree[x].left+tree[x].right)>>1;
	if(right<=mid)
		update(x<<1,left,right,val);
	else
		if(left>mid)
			update(x<<1|1,left,right,val);
		else
		{
			update(x<<1,left,mid,val);
			update(x<<1|1,mid+1,right,val);
		}
	pushup(x);
}
long long findsum(int x,int left,int right)
{
	if(tree[x].left==left&&tree[x].right==right)
		return tree[x].sum;
	if(tree[x].mark)
		pushdown(x);
	int mid=(tree[x].left+tree[x].right)>>1;
	if(right<=mid)
		return findsum(x<<1,left,right);
	else
		if(left>mid)
			return findsum(x<<1|1,left,right);
		else
			return findsum(x<<1,left,mid)+findsum(x<<1|1,mid+1,right);
}
LL findmax(int x,int left,int right)
{
	if(tree[x].left==left&&tree[x].right==right)
		return tree[x].max;
	if(tree[x].mark)
		pushdown(x);
	int mid=(tree[x].left+tree[x].right)>>1;
	if(right<=mid)
		return findmax(x<<1,left,right);
	else
		if(left>mid)
			return findmax(x<<1|1,left,right);
		else
			return maxn(findmax(x<<1,left,mid),findmax(x<<1|1,mid+1,right));
}
LL findmin(int x,int left,int right)
{
	if(tree[x].left==left&&tree[x].right==right)
		return tree[x].min;
	if(tree[x].mark)
		pushdown(x);
	int mid=(tree[x].left+tree[x].right)>>1;
	if(right<=mid)
		return findmin(x<<1,left,right);
	else
		if(left>mid)
			return findmin(x<<1|1,left,right);
		else
			return minn(findmin(x<<1,left,mid),findmin(x<<1|1,mid+1,right));
}
void pushdown(int x)
{
	tree[x<<1].mark+=tree[x].mark;
	tree[x<<1|1].mark+=tree[x].mark;
	tree[x<<1].sum+=tree[x].mark*(tree[x<<1].right-tree[x<<1].left+1);
	tree[x<<1|1].sum+=tree[x].mark*(tree[x<<1|1].right-tree[x<<1|1].left+1);
	tree[x<<1].max+=tree[x].mark;
	tree[x<<1].min+=tree[x].mark;
	tree[x<<1|1].max+=tree[x].mark;
	tree[x<<1|1].min+=tree[x].mark;
	tree[x].mark=0;
}
void pushup(int x)
{
	tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
	tree[x].max=maxn(tree[x<<1].max,tree[x<<1|1].max);
	tree[x].min=minn(tree[x<<1].min,tree[x<<1|1].min);
}
