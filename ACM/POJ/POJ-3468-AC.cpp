#include<stdio.h>
struct node
{
	int left,right;
	long long sum,mark;
}tree[500000];
int arr[100001];
void build(int x,int left,int right);
void update(int x,int left,int right,int val);
long long query(int x,int left,int right);
int main()
{
	int n,q,a,b,c,i;
	char tmp;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	build(1,1,n);
	while(q--)
	{
		getchar();
		scanf("%c",&tmp);
		switch(tmp)
		{
			case 'Q':
				{
					scanf("%d %d",&a,&b);
					printf("%lld\n",query(1,a,b));
					break;
				}
			case 'C':
				{
					scanf("%d %d %d",&a,&b,&c);
					update(1,a,b,c);
					break;
				}
			default:;
		}
	}
	return 0;
}
void build(int x,int left,int right)
{
	tree[x].left=left;
	tree[x].right=right;
	tree[x].mark=0;
	if(left==right)
	{
		tree[x].sum=arr[left];
		return;
	}
	int mid=(left+right)>>1;
	build(x<<1,left,mid);
	build(x<<1|1,mid+1,right);
	tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
}
void update(int x,int left,int right,int val)
{
	if(tree[x].left==left&&tree[x].right==right)
	{
		tree[x].mark+=val;
		return;
	}
	tree[x].sum+=val*(right-left+1);
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
}
long long query(int x,int left,int right)
{
	if(tree[x].left==left&&tree[x].right==right)
		return tree[x].sum+tree[x].mark*(right-left+1);
	if(tree[x].mark)
	{
		tree[x<<1].mark+=tree[x].mark;
		tree[x<<1|1].mark+=tree[x].mark;
		tree[x].sum+=tree[x].mark*(tree[x].right-tree[x].left+1);
		tree[x].mark=0;
	}
	int mid=(tree[x].left+tree[x].right)>>1;
	if(right<=mid)
		return query(x<<1,left,right);
	else
		if(left>mid)
			return query(x<<1|1,left,right);
		else
			return query(x<<1,left,mid)+query(x<<1|1,mid+1,right);
}
