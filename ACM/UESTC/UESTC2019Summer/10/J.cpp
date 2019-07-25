#include<bits/stdc++.h>
using namespace std;

int main()
{
	double pi = acos(-1.0);
	int t;
	cin >> t;
	int l, a;
	while (t--)
	{
		scanf("%d %d", &l, &a);
		double s1 = 0.5 * l * l * sin(a*pi/180), s2 = pi * l * l * a / 360;
		printf("%.6lf\n", s2 - s1);
	}
	return 0;
}
