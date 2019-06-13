#include<stdio.h>
struct node
{
	long long left,right;
	long long max,min;
}tree[400010];
long long sum[200000]={0};
void build(long long x,long long left,long long right);
long long findmax(long long x,long long left,long long right);
long long findmin(long long x,long long left,long long right);
int main()
{
	long long n,m,i,j,a[200000]={0},ans,tmp,ans2;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(i==1)
			sum[i]=a[i];
		else
			sum[i]=a[i]+sum[i-1];
	}
	if(m==0||n==0)
	{
		printf("%lld",0);
		return 0;
	}
	if(m>n)
		m=n;
	build(1,1,n);
	ans=findmax(1,1,m);
	for(i=m;i<n;i++)
	{
		long long min=findmin(1,i-m+1,i);
		if(sum[i+1]-min>ans)
			ans=sum[i+1]-min;
	}
	for(i=n-m+1;i<=n;i++)
	{
		if(i==n-m+1)
			sum[i]=a[i];
		else
			sum[i]=a[i]+sum[i-1];
	}
	build(1,1,n);
	ans2=findmax(1,n-m+1,n);
	for(i=n-m+2;i<=n;i++)
	{
		long long max=findmax(1,i,n);
		if(max-sum[i-1]>ans2)
			ans2=max-sum[i-1];
	}
	if(ans2>ans)
		ans=ans2;
	printf("%lld",ans);
	return 0;
}
void build(long long x,long long left,long long right)
{
	tree[x].left=left;
	tree[x].right=right;
	if(left==right)
	{
		tree[x].max=sum[left];
		tree[x].min=sum[right];
		return;
	}
	long long mid=(left+right)/2;
	build(2*x,left,mid);
	build(2*x+1,mid+1,right);
	tree[x].max=tree[2*x].max>tree[2*x+1].max?tree[2*x].max:tree[2*x+1].max;
	tree[x].min=tree[2*x].min<tree[2*x+1].min?tree[2*x].min:tree[2*x+1].min;
}
long long findmax(long long x,long long left,long long right)
{
	if(tree[x].left==left&&tree[x].right==right)
	{
		return tree[x].max;
	}
	long long mid=(tree[x].left+tree[x].right)/2;
	if(right<=mid)
	{
		return findmax(2*x,left,right);
	}
	else
	{
		if(left>mid)
		{
			return findmax(2*x+1,left,right);
		}
		else
		{
			long long ml=findmax(2*x,left,mid),mr=findmax(2*x+1,mid+1,right);
			return ml>mr?ml:mr;
		}
	}
}
long long findmin(long long x,long long left,long long right)
{
	if(tree[x].left==left&&tree[x].right==right)
	{
		return tree[x].min;
	}
	long long mid=(tree[x].left+tree[x].right)/2;
	if(right<=mid)
	{
		return findmin(2*x,left,right);
	}
	else
	{
		if(left>mid)
		{
			return findmin(2*x+1,left,right);
		}
		else
		{
			long long ml=findmin(2*x,left,mid),mr=findmin(2*x+1,mid+1,right);
			return ml<mr?ml:mr;
		}
	}
}
