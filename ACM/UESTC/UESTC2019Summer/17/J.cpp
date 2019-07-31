#include<bits/stdc++.h>
using namespace std;

struct cach
{
	int ID;
	int pos;
};

map<int, int> IDi;

struct rule
{
	bool operator () (const cach& a, const cach& b)
	{
		return IDi[a.ID] > IDi[b.ID];
	}
};

set<cach, rule> s;
set<cach>::iterator it;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cach tmp;
		scanf("%d", &tmp.ID);
		if (!IDi.count(tmp.ID))
		{
			IDi[tmp.ID] = i;
			tmp.pos = i;
		}
		else
		{
			tmp.pos = IDi[tmp.ID];
			s.erase(tmp);
			tmp.pos = i;
			IDi[tmp.ID] = i;
		}
		if (s.size() == m)
		{
			IDi.erase((*(--s.end())).ID);
			s.erase(--s.end());
		}
		s.insert(tmp);
	}
	for (it = s.begin(); it != s.end(); it++)
		printf("%d\n", (*it).ID);
	return 0;
}
