#include<bits/stdc++.h>
using namespace std;

int a[200000];

int main()
{
	int n;
	int idx = 0;
	int top = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > top)
		{
			top = a[i];
			idx = i;
		}
	}
	int p1 = idx - 1, p2 = idx + 1;
	while (p1 >= 0 || p2 < n)
	{
		if (p1 >= 0)
		{
			if (p2 < n)
			{
				if (top <= max(a[p1], a[p2]))
				{
					printf("NO");
					return 0;
				}
				top = max(a[p1], a[p2]);
				if (a[p1] > a[p2])
					p1--;
				else
					p2++;
			}
			else
			{
				if (top <= a[p1])
				{
					printf("NO");
					return 0;
				}
				top = a[p1];
				p1--;
			}
		}
		else
		{
			if (top <= a[p2])
			{
				printf("NO");
				return 0;
			}
			top = a[p2];
			p2++;
		}
	}
	printf("YES");
	return 0;
}
