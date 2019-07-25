#include<bits/stdc++.h>
#define M(x) ((x)%P)
using namespace std;

const long long P = 998244353;

long long dp[1001][1001][4];

long long m4(long long a, long long b, long long c, long long d)
{
	return M(a + M(b + M(c + d)));
}

int main()
{
	int w, h;
	cin >> w >> h;
	dp[1][1][0] = dp[1][1][1] = dp[1][1][2] = dp[1][1][3] = 1;
	for (int i = 2; i <= w; i++)
	{
		dp[1][i][0] = M(dp[1][i-1][0] + dp[1][i-1][1]);
		dp[1][i][1] = M(dp[1][i-1][0] + dp[1][i-1][1]);
		dp[1][i][2] = M(dp[1][i-1][2] + dp[1][i-1][3]);
		dp[1][i][3] = M(dp[1][i-1][2] + dp[1][i-1][3]);
	}
	for (int i = 2; i <= h; i++)
	{
		dp[i][1][0] = M(dp[i-1][1][0] + dp[i-1][1][3]);
		dp[i][1][1] = M(dp[i-1][1][1] + dp[i-1][1][2]);
		dp[i][1][2] = M(dp[i-1][1][1] + dp[i-1][1][2]);
		dp[i][1][3] = M(dp[i-1][1][0] + dp[i-1][1][3]);
	}
	for (int i = 2; i <= h; i++)
	{
		for(int j = 2; j <= w; j++)
		{
			dp[i][j][0] = min(M(dp[i][j-1][0] + dp[i][j-1][1]), M(dp[i-1][j][0] + dp[i-1][j][3]));
			dp[i][j][1] = min(M(dp[i][j-1][0] + dp[i][j-1][1]), M(dp[i-1][j][1] + dp[i-1][j][2]));
			dp[i][j][2] = min(M(dp[i][j-1][2] + dp[i][j-1][3]), M(dp[i-1][j][1] + dp[i-1][j][2]));
			dp[i][j][3] = min(M(dp[i][j-1][2] + dp[i][j-1][3]), M(dp[i-1][j][0] + dp[i-1][j][3]));
		}
	}
	long long ans = m4(dp[h][w][0], dp[h][w][1], dp[h][w][2], dp[h][w][3]);
	cout << ans;
}
