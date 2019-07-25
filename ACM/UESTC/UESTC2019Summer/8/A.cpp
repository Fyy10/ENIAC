#include<bits/stdc++.h>
using namespace std;

int main()
{
	double pi = acos(-1.0);
	double R, r;
	int t;
	cin >> t;
	while (t--)
	{
		scanf("%lf %lf", &R, &r);
		double s1 = pi * R * R, s2 = 2 * pi * r * r;
		if (abs(s1 - s2) <= 1e-9 || s2 > s1)
			cout << "2\n";
		else
			cout << "1\n";
	}
	return 0;
}
