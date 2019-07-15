#include<bits/stdc++.h>
using namespace std;

int main()
{
	int p, q, r;
	cin >> p >> q >> r;
	int maxx = max(max(p,q),r);
	cout << (p+q+r-maxx);
	return 0;
}
