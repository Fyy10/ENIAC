#include<bits/stdc++.h>
using namespace std;

int a[1000];

int main()
{
	int t;
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n);
		int sum = 0;
		for (int i = 0; i < n/2; i++)
		{
			sum += a[n-i-1] - a[i];
		}
		cout << sum << "\n";
	}
	return 0;
}
