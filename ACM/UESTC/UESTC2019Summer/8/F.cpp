#include<bits/stdc++.h>
using namespace std;

const int P = 7901;

void getorder(int order[], int n, int P);

int main()
{
	int a[1001];
	int order[1001];
	getorder(order, 1000, P);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			a[i] = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			a[tmp]++;
		}
		int ans = 1;
		for (int i = 1; i <= 1000; i++)
		{
			ans *= order[a[i]];
			ans %= P;
		}
		printf("%d\n", ans);
	}
	return 0;
}

void getorder(int order[], int n, int P)
{
	order[0] = order[1] = 1;
	for (int i = 2; i <= n; i++)
		order[i] = (order[i-1] * i) % P;
}
