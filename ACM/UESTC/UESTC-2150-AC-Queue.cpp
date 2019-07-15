#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
	long long val;
	int num;
};
deque<node> dq;
int main()
{
	int n,m,i,a[100000];
	long long sum[100000],ans;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(i==0)
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
	ans=sum[0];
	if(m==n)
		ans=sum[n-1];
	for(i=0;i<n-1;i++)
	{
		while(!dq.empty()&&dq.front().num<=i-m)
			dq.pop_front();
		while(!dq.empty()&&dq.back().val>sum[i])
			dq.pop_back();
		node tmp;
		tmp.val=sum[i];
		tmp.num=i;
		dq.push_back(tmp);
		if(sum[i+1]-dq.front().val>ans)
			ans=sum[i+1]-dq.front().val;
	}
	printf("%lld",ans);
	return 0;
}
