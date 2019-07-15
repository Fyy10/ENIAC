#include<bits/stdc++.h>
using namespace std;

struct divi
{
	unsigned long long up;
	unsigned long long down;
	int num;
}d[1001];

bool cmp(const divi& a, const divi& b)
{
	return (a.up * b.down < a.down * b.up) || (a.up * b.down == a.down * b.up && a.num < b.num);
}

int main()
{
	int n;
	unsigned long long a, b, c;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> a >> b >> c;
			d[i].up = a + b;
			d[i].down = c;
			d[i].num = i;
		}
		sort(d+1, d+n+1, cmp);
		for (int i = 1; i < n; i++)
		{
			printf("%d ", d[i].num);
		}
		if (n > 0) printf("%d\n", d[n].num);
	}
	return 0;
}
