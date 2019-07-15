#include<bits/stdc++.h>
using namespace std;

long long a[200010];
long long sum[200011];

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i <= n; i++)
		{
			scanf("%lld", &a[i]);
		}
		sum[n] = a[n];
		if (sum[n] >= n)
		{
			printf("%d\n", n);
			continue;
		}
		for (int i = n-1; i >= 0; i--)
		{
			sum[i] = sum[i+1] + a[i];
			if (sum[i] >= i)
			{
				printf("%d\n", i);
				break;
			}
			if (i == 0)
			{
				printf("0\n");
			}
		}
	}
	return 0;
}
