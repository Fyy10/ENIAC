#include<bits/stdc++.h>
using namespace std;

struct instruct
{
	int op;
	int p;
	int x;
}ins[200000];

int a[200000];
bool vis[200000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		vis[i] = false;
	}
	int q;
	cin >> q;
	int low = 0;
	for (int i = 0; i < q; i++)
	{
		scanf("%d", &ins[i].op);
		if (ins[i].op == 1)
		{
			scanf("%d %d", &ins[i].p, &ins[i].x);
			ins[i].p--;
		}
		else
			scanf("%d", &ins[i].x);
	}
	for (int i = q - 1; i >= 0; i--)
	{
		if (ins[i].op == 1)
		{
			if (!vis[ins[i].p])
			{
				a[ins[i].p] = max(low, ins[i].x);
				vis[ins[i].p] = true;
			}
		}
		else
		{
			if (ins[i].x > low)
			{
				low = ins[i].x;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] < low && !vis[i])
			a[i] = low;
		printf("%d ", a[i]);
	}
	return 0;
}
