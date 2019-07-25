#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, d;
	cin >> n >> d;
	d = 2 * d + 1;
	if (n % d)
		cout << n/d + 1;
	else
		cout << n/d;
	return 0;
}
