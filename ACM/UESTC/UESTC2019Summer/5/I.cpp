#include<bits/stdc++.h>
using namespace std;

bool isprime(int x)
{
	if (x <= 3)
		return 1;
	int q = sqrt(x);
	for (int i = 2; i <= q; i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int n;
	cin >> n;
	int q = sqrt(n);
	if (isprime(n))
		cout << "1";
	else
	{
		if (n & 1)
		{
			if (isprime(n-2))
				cout << "2";
			else
				cout << "3";
		}
		else
			cout << "2";
	}
	return 0;
}
