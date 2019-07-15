#include<stdio.h>
long long gcd(long long a,long long b);
long long power(long long g,long long o);
long long P=1e9+7;
int main()
{
	long long n,k,i,j,sum=0;
	scanf("%ld %ld",&n,&k);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			sum=(sum%P+power(gcd(i,j),k)%P)%P;
	printf("%ld",sum);
}
long long gcd(long long a,long long b)
{
	while(a&&b)
	{
		if(a>b)
			a%=b;
		else
			b%=a;
	}
	return a+b;
}
long long power(long long g,long long o)
{
	long long io,ans=1;
	for(io=1;io<=o;++io)
	{
		ans=(ans%P)*(g%P)%P;
	}
	return ans;
}
