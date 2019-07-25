#include<bits/stdc++.h>
using namespace std;

const long long P = 998244353;

long long a[11];

int main()
{
	int n;
	cin >> n;
	char s[11];
	int ns;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		ns = strlen(s);
		for (int j = 0; j < ns; j++)
		{
			a[j] += (long long)(s[j] - '0');
		}
	}
	long long ans = 0;
	long long fac = 11 * n;
	for (int i = ns-1; i >= 0; i--)
	{
		ans += (fac * a[i]) % P;
		ans %= P;
		fac *= 100;
		fac %= P;
	}
	cout << ans;
	return 0;
}
