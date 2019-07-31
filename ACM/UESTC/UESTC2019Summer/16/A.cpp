#include<bits/stdc++.h>
using namespace std;

double ans[25597];

int main()
{
	double sum = 0.0;
	for (long long i = 1; i <= 25596; i++)
	{
		sum += 1/double(i*i);
		ans[i] = sum;
	}
	long long n;
	while (scanf("%lld", &n) == 1)
	{
		n = abs(n);
		if (n < 25597)
			printf("%.5lf\n", ans[n]);
		else
		{
			if (n < 34403)
				printf("1.64490\n");
			else
			{
				if (n < 52447)
					printf("1.64491\n");
				else
				{
					if (n < 110292)
						printf("1.64492\n");
					else
						printf("1.64493\n");
				}
			}
		}
	}
	return 0;
}
