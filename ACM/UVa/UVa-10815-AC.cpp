#include<bits/stdc++.h>
using namespace std;

set<string> s;
set<string>::iterator it;
int main()
{
	string str;
	while (cin >> str)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] <= 'Z' && str[i] >= 'A')
			{
				str[i] = str[i] - 'A' + 'a';
			}
			if (str[i] < 'a' || str[i] > 'z')
			{
				str[i] = ' ';
			}
		}
		stringstream ss(str);
		string tmp;
		while (ss >> tmp)
		{
			s.insert(tmp);
		}
	}
	for (it = s.begin(); it != s.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
