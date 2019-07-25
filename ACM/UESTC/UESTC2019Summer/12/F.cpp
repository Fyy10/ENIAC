#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r;
	int x, y;
	int a[10];
	int b[10];
	cin >> r;
	for (int i = 1; i <= 10; i++)
	{
		a[i-1] = 10 - i + 1;
		b[i-1] =  i * r * i * r;
	}
	int ans = 0;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d %d", &x, &y);
		int dis = x*x+y*y;
		int idx = lower_bound(b, b+10, dis) - b;
		if (idx < 10)
			ans += a[idx];
	}
	cout << ans;
	return 0;
}
