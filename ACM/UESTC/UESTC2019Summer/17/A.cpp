#include<bits/stdc++.h>
using namespace std;

char s[1000001];

int main()
{
	scanf("%s", s);
	int n = strlen(s);
	int sum = 0;
	int maxd = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		if (s[i] >= 'A' && s[i] <= 'Z')
			tmp = 10 + s[i] - 'A';
		else
			tmp = s[i] - '0';
		sum += tmp;
		if (tmp > maxd)
			maxd = tmp;
	}
	int i;
	for (i = 2; i <= 36; i++)
	{
		if ((sum % (i-1)) == 0 && i > maxd)
		{
			printf("%d", i);
			return 0;
		}
	}
	printf("No solution.");
	return 0;
}
