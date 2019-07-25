#include<bits/stdc++.h>
using namespace std;

struct com
{
	char curr[11];
	double fac;
}comp[100000];

bool cmp(const com& a, const com& b)
{
	return strcmp(a.curr, b.curr) < 0;
}

int main()
{
	int t;
	cin >> t;
	int c, n;
	double ans;
	while (t--)
	{
		scanf("%d %d", &c, &n);
		ans = 0.0;
		for (int i = 0; i < c; i++)
			scanf("%s %lf", comp[i].curr, &comp[i].fac);
		comp[c].curr[0] = 'J';
		comp[c].curr[1] = 'D';
		comp[c].curr[2] = '\0';
		comp[c].fac = 1.0;
		c++;
		sort(comp, comp+c, cmp);
		for (int i = 0; i < n; i++)
		{
			com tmp;
			scanf("%lf %s", &tmp.fac, tmp.curr);
			int idx = upper_bound(comp, comp+c, tmp, cmp) - comp - 1;
			ans += comp[idx].fac * tmp.fac;
		}
		printf("%.6lf\n", ans + 0.0000005);
	}
	return 0;
}
