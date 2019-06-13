#include<stdio.h>
#include<algorithm>
using namespace std;
int divn(long long tmp);
int main()
{
	int t,n,i,a[301];
	long long tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		tmp=(long long)a[1]*(long long)a[n];
		for(i=1;i<=n;i++)
			if(tmp%a[i])
				break;
		if(i==n+1&&n==divn(tmp))
			printf("%lld\n",tmp);
		else
			printf("%d\n",-1);
	}
	return 0;
}
int divn(long long tmp)
{
	int ans=1,p,i;
	for(i=2;i*i<=tmp;i++)
	{
		p=0;
		while(tmp%i==0)
		{
			p++;
			tmp/=i;
		}
		if(p>0)
		{
			p++;
			ans*=p;
		}
	}
	if(tmp>1)
		ans*=2;
	ans-=2;
	return ans;
}
