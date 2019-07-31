#include<bits/stdc++.h>
using namespace std;

int a[100000];

int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		bool flag = 1;
		long long left = 0, right = 0;
		int j = i - 1;
		while (j >= 0 && j >= i - x)
		{
			if (a[j] <= a[i])
				flag = 0;
			j--;
		}
		j = i + 1;
		while (j < n && j <= i + y)
		{
			if (a[j] <= a[i])
				flag = 0;
			j++;
		}
		if (flag)
		{
			printf("%d", i + 1);
			break;
		}
	}
	return 0;
}
