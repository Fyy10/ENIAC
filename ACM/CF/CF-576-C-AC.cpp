#include<bits/stdc++.h>
using namespace std;

long long a[400000];
long long presum[400000];
multiset<long long> ms;
set<long long> s;
set<long long>::iterator it;

int main()
{
	long long n, I;
	cin >> n >> I;
	for (long long i = 0; i < n; i++)
	{
		long long tmp;
		scanf("%lld", &tmp);
		s.insert(tmp);
		ms.insert(tmp);
	}
	long long p = (8*I)/n;
	if (p >= 19)
		p = 19;
	long long k = pow(2, p);
	long long m = 0;
	for (it = s.begin(); it != s.end(); it++)
	{
		a[m] = ms.count(*it);
		m++;
	}
	presum[0] = a[0];
	for (int i = 1; i < m; i++)
		presum[i] = presum[i-1] + a[i];
	long long minans = n + 1;
	if (m <= k)
		minans = 0;
	for (int i = k - 1; i < m; i++)
	{
		long long segsum;
		if (i == k-1)
			segsum = presum[i];
		else
			segsum = presum[i] - presum[i-k];
		long long tmp = n - segsum;
		if (tmp < minans)
			minans = tmp;
	}
	cout << minans;
	return 0;
}
