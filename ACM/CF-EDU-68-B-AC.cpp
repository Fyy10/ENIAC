#include<bits/stdc++.h>
using namespace std;

int a[500000];
int tmpv[500000];
int mem[500000];
char str[500000];

set<int> x;
set<int> y;
set<int>::iterator it1;
set<int>::iterator it2;

int main()
{
	int q;
	int n, m;
	int minx;
	int miny;
	cin >> q;
	while (q--)
	{
		scanf("%d %d", &n, &m);
		//getchar();
		minx = miny = 500000;
		x.clear();
		y.clear();
		for (int i = 0; i < m; i++) a[i] = 0;
		for (int i = 0; i < n*m; i++) mem[i] = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp = 0;
			scanf("%s", str);
			for (int j = 0; j < m; j++)
			{
				//char c = getchar();
				if (str[j] == '.')
				{
					tmp++;
					a[j]++;
					mem[i*m+j] = 0;
				}
				if (str[j] == '*')
					mem[i*m+j] = 1;
			}
			if (tmp < minx)
			{
				minx = tmp;
			}
		}
		for (int i = 0; i < m; i++)
		{
			if (a[i] < miny)
			{
				miny = a[i];
			}
		}
		for (int i = 0; i < n; i++)
		{
			int tmp = 0;
			for (int j = 0; j < m; j++)
			{
				tmp += !mem[i*m+j];
			}
			if (tmp == minx)
				y.insert(i);
		}
		for (int i = 0; i < m; i++)
		{
			int tmp = 0;
			for (int j = 0; j < n; j++)
				tmp += !mem[j*m+i];
			if (tmp == miny)
				x.insert(i);
		}
		int flag = 0;
		for (it1 = x.begin(); it1 != x.end(); it1++)
		{
			for (it2 = y.begin(); it2 != y.end(); it2++)
			{
				if (mem[(*it2)*m+(*it1)] == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag && minx + miny > 0)
			printf("%d\n", minx + miny - 1);
		else
			printf("%d\n", minx + miny);
	}
	return 0;
}
