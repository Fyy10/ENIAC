#include<bits/stdc++.h>
using namespace std;

int a[200000];

int main()
{
	int n;
	int cnt = 1;
	int maxv = 0;
	int max2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > max2)
		{
			if (a[i] >= maxv)
			{
				if (a[i] == maxv)
					cnt++;
				else
				{
					cnt = 1;
					max2 = maxv;
					maxv = a[i];
				}
			}
			else
				max2 = a[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] < maxv)
			printf("%d\n", maxv);
		else
		{
			if (cnt > 1)
				printf("%d\n", maxv);
			else
				printf("%d\n", max2);
		}
	}
	return 0;
}
