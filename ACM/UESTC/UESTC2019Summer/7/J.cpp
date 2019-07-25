#include<bits/stdc++.h>
using namespace std;

int s[100000];

int rev(int x)
{
	if (x == 1)
		return 2;
	if (x == 2)
		return 1;
}

int main()
{
	int t;
	int k;
	cin >> t;
	while (t--)
	{
		scanf("%d", &k);
		for (int i = 0; i < k; i++)
			scanf("%1d", &s[i]);
		int n, m;
		scanf("%d %d", &n, &m);
		int a, b;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
		}
		int tmp = m - n + 1;
		tmp %= k;
		printf("%d\n", rev(s[tmp]));
	}
	return 0;
}
