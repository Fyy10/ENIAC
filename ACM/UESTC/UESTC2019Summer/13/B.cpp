#include<bits/stdc++.h>
#define int long long
using namespace std;

int a[100000];

signed main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		int idx;
		int maxv = 0;
		scanf("%lld", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
			if (a[i] > maxv)
			{
				maxv = a[i];
				idx = i;
			}
		}
		bool flag = true;
		for (int i = idx - 1; i >= 0; i--)
		{
			if (a[i] >= a[i+1])
			{
				flag = false;
				break;
			}
		}
		for (int i = idx + 1; i < n; i++)
		{
			if (a[i] >= a[i-1])
			{
				flag = false;
				break;
			}
		}
		if (flag && idx != 0 && idx != n-1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
