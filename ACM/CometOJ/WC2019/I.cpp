#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n, m, k;
	cin >> n >> m >> k;
	if (k > (n-1)*(m-1))
		printf("-1");
	else
		printf("%lld", m + n - 2);
	return 0;
}
