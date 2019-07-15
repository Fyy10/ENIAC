#include<bits/stdc++.h>
using namespace std;

long long p[100001];

int main()
{
	long long n, m, k;
	long long fin = 0;
	long long ans = 0;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		scanf("%lld", &p[i]);
	}
	sort(p+1, p+m+1);
	for (int i = 1; i <= m; i++)
	{
		long long left;
		if ((p[i] - fin) % k ==0)
		{
			left = (p[i]-fin-1)/k*k + 1;
		}
		else
		{
			left = (p[i]-fin)/k*k + 1;
		}
		long long right = left + k;
		fin = lower_bound(p+1, p+m+1, right+fin) - p - 1;
		i = fin;
		ans++;
	}
	cout << ans;
	return 0;
}
