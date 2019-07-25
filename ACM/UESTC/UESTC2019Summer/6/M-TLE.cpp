#include<bits/stdc++.h>
#define M(x) ((x)%P)
using namespace std;

const long long P = 1e9 + 7;

long long fastmod(long long a, long long b)
{
	if (a == 0)
		return a;
	if (b == 0)
		return 1;
	long long ans = fastmod(a, b/2);
	if (b & 1)
		ans = M(M(ans * ans) * M(a));
	else
		ans = M(ans * ans);
	return ans;
}

long long inv(long long a)
{
	return fastmod(a, P-2);
}

long long order[100001];

void getorder()
{
	order[0] = order[1] = 1;
	for (int i = 2; i <= 100000; i++)
		order[i] = M(i * order[i-1]);
}

long long cmb(long long n, long long m)
{
	if (m == 0 || m == n)
		return 1;
	return M(order[n] * inv(M(order[m] * order[n-m])));
}

int main()
{
	getorder();
	int t;
	long long n, m;
	cin >> t;
	while (t--)
	{
		scanf("%lld %lld", &n, &m);
		//printf("%lld\n", M(fastmod(2, m) * cmb(n, m)));
		long long ans = 0;
		for (int i = 0; i <= m; i++)
		{
			ans = M(ans + cmb(n, i));
		}
		printf("%lld\n", ans);
	}
	return 0;
}
