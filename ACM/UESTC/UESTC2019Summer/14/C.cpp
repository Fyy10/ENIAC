#include<bits/stdc++.h>
using namespace std;

bool vis[10000000];

int main()
{
	long long p, n;
	cin >> p >> n;
	long long sum = 0;
	n = min(p, n);
	for (int i = 0; i < p; i++)
		vis[i] = false;
	for (int i = 0; i <= n; i++)
	{
		sum = (sum + i) % p;
		vis[sum] = true;
	}
	int ans = 0;
	for (int i = 0; i < p; i++)
		if (vis[i])
			ans++;
	cout << ans;
	return 0;
}
