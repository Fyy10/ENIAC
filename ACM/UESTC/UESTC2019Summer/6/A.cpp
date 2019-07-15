#include<bits/stdc++.h>
using namespace std;

struct line
{
	int num;
	int rem;
};

struct rule
{
	bool operator () (const line& a, const line& b)
	{
		return a.rem < b.rem || (a.rem == b.rem && a.num < b.num);
	}
};

bool cmp(line a, line b)
{
	return a.rem < b.rem;
}

multiset<line, rule> board;
multiset<line, rule>::iterator it;

int main()
{
	int h, w, n;
	while (cin >> h >> w >> n)
	{
		board.clear();
		for (int i = 1; i <= n; i++)
		{
			line tmp;
			tmp.num = i;
			scanf("%d", &tmp.rem);
			it = lower_bound(board.begin(), board.end(), tmp, cmp);
			if (it == board.end())
			{
				if (board.size() < h)
				{
					tmp.num = board.size() + 1;
					tmp.rem = w - tmp.rem;
					board.insert(tmp);
					printf("%d\n", tmp.num);
				}
				else
					printf("-1\n");
			}
			else
			{
				tmp.num = (*it).num;
				tmp.rem = (*it).rem - tmp.rem;
				board.erase(it);
				board.insert(tmp);
				printf("%d\n", tmp.num);
			}
		}
	}
	return 0;
}
