#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x;
	int a;
	cin >> x;
	x %= 4;
	switch (x)
	{
		case 0: cout << "1 A"; break;
		case 1: cout << "0 A"; break;
		case 2: cout << "1 B"; break;
		case 3: cout << "2 A"; break;
		default:;
	}
	return 0;
}
