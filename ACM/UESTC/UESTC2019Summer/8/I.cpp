#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	int a[100];
	cin >> t;
	while (t--)
	{
		int n;
		int sum = 0;
		int minv = 10000000;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
			if (a[i] < minv)
				minv = a[i];
		}
		if (n % 2)
		{
			if (sum % 2)
				printf("Yalalov\n");
			else
				printf("Shin\n");
		}
		else
		{
			if (sum % 2 || minv % 2)
				printf("Yalalov\n");
			else
				printf("Shin\n");
		}
	}
	return 0;
}
