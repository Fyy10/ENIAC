#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, x;
	cin >> t;
	while (t--)
	{
		scanf("%d %d", &n, &x);
		if (n >= 2*x)
			printf("%d\n", 2*x);
		else
			printf("%d\n", n/2*2);
	}
	return 0;
}
