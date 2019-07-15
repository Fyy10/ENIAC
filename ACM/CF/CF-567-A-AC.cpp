#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long x, y, z;
	cin >> x >> y >> z;
	long long rx = x%z;
	long long ry = y%z;
	long long ans = (x+y)/z;
	long long exc;
	if(rx+ry >= z)
		exc = min(z-rx,z-ry);
	else
		exc=0;
	cout << ans << ' ' << exc;
	return 0;
}
