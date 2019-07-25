#include<bits/stdc++.h>
using namespace std;

char ans[1000001];

int main()
{
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		ans[i] = '-';
	if (n*(n+1) % 4)
	{
		cout << -1;
		return 0;
	}
	else
	{
		long long rem = n*(n+1)/4;
		for (int i = n; i > 0; i--)
		{
			rem -= i;
			ans[i] = '+';
			if (rem < i)
			{
				ans[rem] = '+';
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		putchar(ans[i]);
	}
	return 0;
}
