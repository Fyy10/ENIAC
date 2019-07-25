#include<bits/stdc++.h>
using namespace std;

int a[100000];

int main()
{
	int t;
	int n;
	cin >> t;
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n);
		int i;
		for (i = 1; i < n; i++)
		{
			a[i] -= a[0];
			if (a[i] & 1)
			{
				printf("no\n");
				break;
			}
		}
		if (i == n)
			printf("yes\n");
	}
	return 0;
}
