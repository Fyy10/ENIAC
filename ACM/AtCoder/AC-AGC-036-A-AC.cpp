#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long s;
	cin >> s;
	long long x1 = 1e9, y1 = 0, x2 = 0, y2 = (s+1e9)/1e9;
	if (s == 1e18)
	{
		y2 = 1e9;
	}
	else
	{
		y1 = 1;
		x2 = x1 * y2 - s;
	}
	cout << "0 0 " << x1 << " " << y1 << " " << x2 << " " << y2;
	return 0;
}
