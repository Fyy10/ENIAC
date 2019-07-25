#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int l1, r1, p1, d1, l2, r2, p2, d2;
	int k;
	while (t--)
	{
		scanf("%d %d %d %d", &l1, &r1, &p1, &d1);
		scanf("%d %d %d %d", &l2, &r2, &p2, &d2);
		scanf("%d", &k);
		if (p1 == r1)
			d1 = 0;
		if (p1 == l1)
			d1 = 1;
		if (p2 == r2)
			d2 = 0;
		if (p2 == l2)
			d2 = 1;
		long long ans = 0;
		while (k--)
		{
			if (d1 == 1)
			{
				p1++;
				if (p1 == r1)
					d1 = 0;
			}
			else
			{
				p1--;
				if (p1 == l1)
					d1 = 1;
			}
			if (d2 == 1)
			{
				p2++;
				if (p2 == r2)
					d2 = 0;
			}
			else
			{
				p2--;
				if (p2 == l2)
					d2 = 1;
			}
			if (p1 == p2)
				ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
