#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	long int t,a[200001],d,i,n;
	long long h;
	scanf("%ld",&t);
	while(t--)
	{
		h=0;
		scanf("%ld",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%ld %ld",&a[i],&d);
			a[i]-=d;
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;++i)
		{
			h+=(2*i-n-1)*a[i];
		}
		printf("%lld\n",h);
	}
	return 0;
}
