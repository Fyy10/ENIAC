#include<bits/stdc++.h>
using namespace std;

long long min2(long long a, long long b, long long c)
{
	return min(min(a+b, b+c), a+c);
};

long long sum3[500000], sum2[500000];
long long sum2mem[500000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		sum3[i] = a + b + c;
		sum2[i] = sum2mem[i] = min2(a, b, c) + 2;
	}
	sort(sum2, sum2+n);
	for (int i = 0; i < n; i++)
	{
		int idx = upper_bound(sum2, sum2+n, sum3[i]) - sum2;
		if (sum2mem[i] <= sum3[i])
			idx--;
		printf("%d ", idx);
	}
	return 0;
}
