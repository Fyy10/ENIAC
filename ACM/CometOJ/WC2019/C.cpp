#include<bits/stdc++.h>
using namespace std;

long long ord[14];

void getord()
{
	ord[0] = ord[1] = 1;
	for (int i = 2; i < 14; i++)
		ord[i] = i * ord[i-1];
}

int main()
{
	long long n, mod;
	cin >> n >> mod;
	getord();
	long long idx = upper_bound(ord, ord+14, mod) - ord - 1;
	if (n >= idx || ord[n] >= idx)
		printf("0");
	else
	{
		long long ans = 1;
		for (int i = 1; i <= ord[ord[n]]; i++)
		{
			ans *= i;
			ans %= mod;
		}
		printf("%lld", ans);
	}
	return 0;
}
