#include<bits/stdc++.h>
using namespace std;

bool vis[10001];

int main()
{
	int l, m;
	cin >> l >> m;
	for (int i = 0; i <= l; i++)
		vis[i] = true;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		for (int j = a; j <= b; j++)
			vis[j] = false;
	}
	int ans = 0;
	for (int i = 0; i <= l; i++)
	{
		if (vis[i])
			ans++;
	}
	cout << ans;
	return 0;
}
