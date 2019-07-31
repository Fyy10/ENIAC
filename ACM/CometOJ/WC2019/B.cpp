#include<bits/stdc++.h>
using namespace std;

int a[100000];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int ans = 0;
	int i = 1;
	while (i < n-1)
	{
		if (abs(a[i-1] - a[i]) < k)
		{
			ans++;
			i += 2;
		}
		else
		{
			if (abs(a[i+1] - a[i]) < k)
				i++;
			else
				i += 2;
		}
	}
	if (i == n-1 && abs(a[n-1] - a[n-2]) < k)
		ans++;
	cout << ans;
	return 0;
}
