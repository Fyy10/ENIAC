#include<bits/stdc++.h>
using namespace std;

int min2(int a, int b, int c)
{
	return min(min(a+b, a+c), b+c);
}

int sum2[1000];
int sum3[1000];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		sum2[i] = min2(a, b, c);
		sum3[i] = a + b + c;
	}
	for (int i = 0; i < n; i++)
	{
		int ans = 0;
		for (int j = 0; j < n; j++)
		{
			if (j == i)
				continue;
			if (sum3[i] > sum2[j] + 1)
				ans++;
		}
		cout << ans << " ";
	}
    return 0;
}
