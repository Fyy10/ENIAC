#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		if (k > 64)
			k = 64;
		for (int i = 0; i < k; i++)
		{
			n = (n+1)>>1;
		}
		cout << n << "\n";
	}
	return 0;
}
