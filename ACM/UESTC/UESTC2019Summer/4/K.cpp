#include<bits/stdc++.h>
using namespace std;

long long cnt2(long long a, long long b)
{
	return b/2 - (a-1)/2;
}

long long n1009(long long a, long long b)
{
	return b/1009 - (a-1)/1009;
}

long long n2018(long long a, long b)
{
	return b/2018 - (a-1)/2018;
}

int main()
{
	long long a, b, c, d;
	long long n, n1, n2;
	long long ans;
	while (scanf("%lld %lld %lld %lld", &a, &b, &c, &d) == 4)
	{
		ans = 0;
		ans += n2018(a, b)*(d - c + 1);
		ans += (n1009(a, b) - n2018(a, b))*cnt2(c, d);
		ans += (cnt2(a, b) - n2018(a, b))*n1009(c, d);
		ans += (b-a+1-cnt2(a, b)-n1009(a, b)+n2018(a, b))*n2018(c, d);
		printf("%lld\n", ans);
	}
	return 0;
}
