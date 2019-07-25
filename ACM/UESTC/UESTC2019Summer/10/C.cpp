#include<bits/stdc++.h>
using namespace std;

int x[100000];

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int t;
	cin >> t;
	int n;
	long long sum;
	int si;
	while (t--)
	{
		scanf("%d", &n);
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x[i]);
			sum += (long long)x[i];
			if (i == 1)
				si = gcd(x[i], x[i-1]);
			if (i > 1)
				si = gcd(si, x[i]);
		}
		if (n == 1)
			printf("%lld %lld\n", sum, sum);
		else
			printf("%lld %d\n", sum, si);
	}
	return 0;
}
