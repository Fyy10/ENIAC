#include<bits/stdc++.h>
using namespace std;

vector<queue<int> > v;
map<int, int> team;
map<int, int> pos;

int p;

void inque(int num)
{
	if (pos[team[num]] != -1)
		v[pos[team[num]]].push(num);
	else
	{
		queue<int> tmp;
		tmp.push(num);
		pos[team[num]] = v.size();
		v.push_back(tmp);
	}
}

void outque()
{
	printf("%d\n", v[p].front());
	int tmp = team[v[p].front()];
	v[p].pop();
	if (v[p].empty())
	{
		pos[tmp] = -1;
		p++;
	}
}

int main()
{
	int t;
	int k = 1;
	while (scanf("%d", &t)  == 1)
	{
		if (t == 0)
			break;
		printf("Scenario #%d\n", k);
		v.clear();
		team.clear();
		pos.clear();
		p = 0;
		for (int i = 0; i < t; i++)
		{
			int n;
			scanf("%d", &n);
			for (int j = 0; j < n; j++)
			{
				int tmp;
				scanf("%d", &tmp);
				team[tmp] = i;
			}
			pos[i] = -1;
		}
		char com[10];
		int num;
		while (scanf("%s", com) == 1)
		{
			if (com[0] == 'S')
				break;
			scanf("%d", &num);
			if (com[0] == 'E')
				inque(num);
			if (com[0] == 'D')
				outque();
		}
		k++;
		printf("\n");
	}
	return 0;
}
