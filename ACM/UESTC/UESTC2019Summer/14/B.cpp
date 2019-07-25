#include<bits/stdc++.h>
using namespace std;

int main()
{
	char str1[1001], str2[1001];
	scanf("%s", str1);
	scanf("%s", str2);
	int up = 0, down = 0, cross = 0;
	int n = strlen(str1);
	for (int i = 0; i < n; i++)
	{
		if (str1[i] == '#')
		{
			if (str2[i] == '#')
				cross++;
			else
				up++;
		}
		else
		{
			if (str2[i] == '#')
				down++;
		}
	}
	if (cross == 0 && up > 0 && down > 0)
	{
		printf("NO\n");
		return 0;
	}
	else
		printf("YES\n");
	for (int i = 0; i < n; i++)
	{
		if (i < up+cross)
			putchar('#');
		else
			putchar('.');
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		if (i < up)
			putchar('.');
		else
		{
			if (i < up+down+cross)
				putchar('#');
			else
				putchar('.');
		}
	}
	printf("\n");
	return 0;
}
