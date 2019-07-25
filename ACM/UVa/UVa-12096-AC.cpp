#include<bits/stdc++.h>
using namespace std;

typedef set<int> SET;

map<SET, int> IDm;
vector<SET> vs;
stack<int> s;

int ID(SET x)
{
	if (IDm.count(x))
		return IDm[x];
	vs.push_back(x);
	return IDm[x] = vs.size() - 1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		scanf("%d", &n);
		char str[10];
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			switch(str[0])
			{
				case 'P':
				{
					SET tmp;
					tmp.clear();
					s.push(ID(tmp));
					cout << vs[s.top()].size() << endl;
					break;
				}
				case 'D':
				{
					s.push(s.top());
					cout << vs[s.top()].size() << endl;
					break;
				}
				case 'U':
				{
					SET s1 = vs[s.top()];
					s.pop();
					SET s2 = vs[s.top()];
					s.pop();
					SET x;
					set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(x, x.begin()));
					s.push(ID(x));
					cout << vs[s.top()].size() << endl;
					break;
				}
				case 'I':
				{
					SET s1 = vs[s.top()];
					s.pop();
					SET s2 = vs[s.top()];
					s.pop();
					SET x;
					set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(x, x.begin()));
					s.push(ID(x));
					cout << vs[s.top()].size() << endl;
					break;
				}
				case 'A':
				{
					SET s1 = vs[s.top()];
					s.pop();
					SET s2 = vs[s.top()];
					s.pop();
					s2.insert(ID(s1));
					s.push(ID(s2));
					cout << vs[s.top()].size() << endl;
					break;
				}
				default:;
			}
		}
		cout << "***\n";
	}
	return 0;
}
