#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b, c, d;
	long long n, n1, n2;
	long long ans;
	while (scanf("%lld %lld %lld %lld", &a, &b, &c, &d) == 4)
	{
		ans = 0;
		n = b/1009 - (a-1)/1009;
		//cout << n << endl;
		n1 = (n+1)/2;
		n2 = n/2;
		ans += (d - c + 1)/2 * n1;
		ans += (d - c + 1) * n2;
		n = d/1009 - (c-1)/1009;
		//cout << n << endl;
		n1 = (n+1)/2;
		n2 = n/2;
		ans += (b - a + 1)/2 * n1;
		ans += (b - a + 1) * n2;
		if (c <= b)
		{
			n = b/1009 - (c-1)/1009;
			n1 = (n+1)/2;
			n2 = n/2;
			ans -= 2 * n1 * n2;
			ans -= n2 * n2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
