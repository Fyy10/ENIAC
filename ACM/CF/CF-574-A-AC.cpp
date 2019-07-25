#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	int a[1001];
	cin >> n >> k;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		a[tmp]++;
	}
	int ans = 0;
	int sum = 0;
	for (int i =1; i <= k; i++)
	{
		ans += a[i]/2*2;
		a[i] %= 2;
		sum += a[i];
	}
	ans += (sum+1)/2;
	cout << ans;
	return 0;
}
