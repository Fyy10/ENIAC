#include<bits/stdc++.h>
using namespace std;

struct line
{
	int l;
	int r;
	int num;
};

struct cmpl
{
	bool operator () (const line& a, const line& b)
	{
		return a.l > b.l;
	}
};

struct cmpr
{
	bool operator () (const line& a, const line& b)
	{
		return a.r < b.r;
	}
};

multiset<line, cmpl> msl;
multiset<line, cmpr> msr;
multiset<line>::iterator it;
vector<line> v;

int main()
{
	int n;
	char c;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
	{
		line tmp;
		tmp.l = 0;
		tmp.r = 0;
		tmp.num = i;
		while ((c = getchar()) != '\n')
		{
			if (c == '(')
			{
				tmp.l++;
			}
			else
			{
				if (tmp.l)
				{
					tmp.l--;
				}
				else
				{
					tmp.r++;
				}
			}
		}
		if (tmp.l > tmp.r)
		{
			msr.insert(tmp);
		}
		else
		{
			msl.insert(tmp);
		}
	}
	int rem = 0;
	for (it = msr.begin(); it != msr.end(); it++)
	{
		rem -= (*it).r;
		if (rem < 0)
			break;
		rem += (*it).l;
		v.push_back(*it);
	}
	for (it = msl.begin(); it != msl.end(); it++)
	{
		rem -= (*it).r;
		if (rem < 0)
			break;
		rem += (*it).l;
		v.push_back(*it);
	}
	if (v.size() != n || rem > 0)
		cout << "NO";
	else
	{
		printf("YES\n");
		for (int i = 0; i < n; i++)
		{
			printf("%d ", v[i].num + 1);
		}
	}
	return 0;
}
