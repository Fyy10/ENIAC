#include<bits/stdc++.h>
using namespace std;

int a[100000], b[100000];

long long dp[100000][3];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	dp[0][0] = 0;
	dp[0][1] = a[0];
	dp[0][2] = b[0];
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
		dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + a[i];
		dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + b[i];
	}
	cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
	return 0;
}
