#include<bits/stdc++.h>
using namespace std;

char a[100001];
char b[100001];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		scanf("%s", a);
		scanf("%s", b);
		int n = strlen(a);
		int ans = 0;
		int i;
		for (i = 0; i <= n/2; i++)
		{
			if (ans % 2 == 0)
			{
				if (a[i] != b[i] && a[i] != b[n-i-1])
				{
					printf("-1\n");
					break;
				}
				else
				{
					if (a[i] != b[i])
						ans++;
				}
			}
			else
			{
				if (a[i] != b[n-i-1] && a[i] != b[i])
				{
					printf("-1\n");
					break;
				}
				else
				{
					if (a[i] != b[n-i-1])
						ans++;
				}
			}
		}
		if (i > n/2)
			printf("%d\n", ans);
	}
	return 0;
}
