#include<bits/stdc++.h>
using namespace std;

long long fastm(long long a, long long b)
{
	if (a == 0)
		return a;
	if (b == 0)
		return 1;
	long long ans = fastm(a, b/2);
	if (b & 1)
		return a * ans * ans;
	else
		return ans * ans;
}

int main()
{
	long long t, k, n;
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld %lld", &k, &n);
		long long rem = n;
		if (rem <= k)
		{
			if (rem == 2)
				printf("1\n");
			else
				printf("2\n");
		}
		else
		{
			if (k == 1)
			{
				printf("%lld\n", rem - 1);
				continue;
			}
			long long h = 0;
			long long sum = 1;
			long long fac = k;
			while (sum < rem)
			{
				sum += fac;
				fac *= k;
				h++;
			}
			long long ans = 2 * (h - 1);
			if (n <= (fastm(k, h)-1) / (k-1) + fastm(k, h-1) && ans > 0)
				ans++;
			else
				ans += 2;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
