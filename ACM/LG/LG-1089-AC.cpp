#include<bits/stdc++.h>
using namespace std;

int main()
{
	int rem = 0;
	int out = 0;
	int x = -1;
	for (int i = 1; i <= 12; i++)
	{
		int tmp;
		cin >> tmp;
		rem += 300;
		if (rem < tmp && x == -1)
		{
			x = i;
		}
		rem -= tmp;
		out += rem/100;
		rem %=100;
	}
	if (x != -1)
		cout << -x;
	else
		cout << 120 * out + rem;
	return 0;
}
