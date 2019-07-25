#include<bits/stdc++.h>
#define int long long
using namespace std;

bool isprime(int x)
{
	if (x <= 3)
		return 1;
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return 0;
	return 1;
}

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

signed main()
{
	int s, g;
	st:while (cin >> s >> g)
	{
		if (s % g || s <= g)
		{
			cout << -1 << endl;
			continue;
		}
		s /= g;
		for (int i = 1; i <= s/2; i++)
		{
			if (gcd(i, s-i) == 1)
			{
				cout << i * g << " " << (s - i) * g << endl;
				goto st;
			}
		}
		cout << -1 << endl;
	}
	return 0;
}
