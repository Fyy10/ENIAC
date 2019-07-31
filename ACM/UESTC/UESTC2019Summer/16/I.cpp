#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	double pi = acos(-1.0);
	cin >> t;
	while (t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%.6lf\n", pi * (double)a + 2 * (double)b - 0.0000005);
	}
	return 0;
}
