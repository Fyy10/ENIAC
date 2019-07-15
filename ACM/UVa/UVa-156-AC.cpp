#include<bits/stdc++.h>
using namespace std;

multiset<string> s, mapss;
map<string, string> m;
multiset<string>::iterator it;

int main()
{
	string str;
	while (cin >> str)
	{
		if (str[0] == '#')
			break;
		string tmp = str;
		for (int i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
		}
		sort(str.begin(), str.end());
		s.insert(str);
		m[str] = tmp;
	}
	mapss.clear();
	for (it = s.begin(); it != s.end(); it++)
	{
		if (s.count(*it) == 1)
		{
			//cout << m[*it] << endl;
			mapss.insert(m[*it]);
			//s.erase(*it);
		}
	}
	for (it = mapss.begin(); it != mapss.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
