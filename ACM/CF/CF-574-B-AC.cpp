#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	long long p = (sqrt(9 + 8 * (n + k)) - 3) / 2;
	cout << n - p;
	return 0;
}
