#include<bits/stdc++.h>
using namespace std;

int a[100000];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		long long sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += (long long)a[i];
		}
		sum /= n;
		long long ans = 0;
		long long up = 0, down = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > sum)
				up += a[i] - sum;
			if (a[i] < sum)
				down += sum - a[i];
			//ans += a[i] - sum;
		}
		ans = max(up, down);
		printf("%lld\n", ans);
	}
	return 0;
}
