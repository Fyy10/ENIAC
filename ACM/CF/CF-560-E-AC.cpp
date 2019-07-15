#include<stdio.h>
#include<algorithm>
#define hrdg 998244353
using namespace std;
long long a[200001],b[200001];
bool cmp(long long a,long long b)
{
	if(a>b)
		return true;
	else
		return false;
}
int main()
{
	long long n,i,ans=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
		scanf("%lld",&b[i]);
	for(i=1;i<=n;i++)
	{
		a[i]*=i*(n-i+1);
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		ans+=(a[i]%hrdg)*(b[i]%hrdg)%hrdg;
		ans%=hrdg;
	}
	printf("%lld",ans);
	return 0;
}
