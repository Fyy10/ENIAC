#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, q;
	int a[10000];
	int t = 1;
	while (cin >> n >> q)
	{
		if (n == 0 && q == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		cout << "CASE# " << t << ":" << endl;
		for (int i = 1; i <= q; i++)
		{
			int tmp;
			cin >> tmp;
			int idx = lower_bound(a, a+n, tmp) - a;
			if (a[idx] == tmp)
			{
				cout << tmp << " found at " << idx+1 << endl;
			}
			else
			{
				cout << tmp << " not found" << endl;
			}
		}
		t++;
	}
	return 0;
}
