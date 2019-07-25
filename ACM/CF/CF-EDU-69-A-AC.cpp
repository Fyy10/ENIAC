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
		cin >> n;
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a+n);
		cout << min(a[n-2]-1, n-2) << "\n";
	}
	return 0;
}
