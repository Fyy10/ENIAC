#include<bits/stdc++.h>
#define M(x) ((x)%P)
using namespace std;

const long long P = 998244353;

long long order[1002];

long long fastmod(long long a, long long b)
{
	if (a == 0)
		return a;
	if (b == 0)
		return 1;
	long long ans = fastmod(a, b/2);
	if (b & 1)
	{
		return M(M(ans * ans) * a);
	}
	else
		return M(ans * ans);
}

long long inv(long long a)
{
	return fastmod(a, P-2);
}

void getorder()
{
	order[0] = order[1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		order[i] = M(order[i-1] * i);
	}
}

long long cmb(long long n, long long m)
{
	return M(order[n] * inv(M(order[m] * order[n-m])));
}

long long dp[1002];

int main()
{
	int n;
	long long a[1002];
	getorder();
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	dp[n+1] = 1;
	for (int i = n; i > 0; i--)
	{
		dp[i] = 0;
		if (a[i] <= 0)
			continue;
		for (int j = i + a[i] + 1; j <= n+1; j++)
		{
			dp[i] += M(cmb(j - i - 1, a[i]) * dp[j]);
			dp[i] %= P;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += dp[i];
		ans %= P;
	}
	cout << ans;
	return 0;
}
