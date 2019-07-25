#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[100000];

signed main()
{
	int t;
	cin >> t;
	int n;
	int l, r;
	while (t--)
	{
		cin >> n;
		int ans = 0;
		l = 0;
		r = n-1;
		for (int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		while (l < r)
		{
			if (a[l] == a[r])
			{
				l++;
				r--;
			}
			else
			{
				ans++;
				if (a[l] > a[r])
				{
					r--;
					a[r] += a[r+1];
				}
				else
				{
					l++;
					a[l] += a[l-1];
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
