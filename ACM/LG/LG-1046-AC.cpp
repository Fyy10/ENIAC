#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[10];
	for (int i = 0 ;i < 10; i++)
	{
		cin >> a[i];
	}
	sort(a, a+10);
	int h;
	cin >> h;
	h += 30;
	cout << upper_bound(a, a+10, h) - a;
	return 0;
}
