#include<bits/stdc++.h>
using namespace std;


int main()
{
	int q;
	cin >> q;
	string s, t, p;
	while (q--)
	{
		cin >> s >> t >> p;
		int pt = 0;
		int ps = 0;
		int flag = 1;
		while (pt < t.length())
		{
			if (ps < s.length() && s[ps] == t[pt])
			{
				ps++;
				pt++;
			}
			else
			{
				int j;
				for (j = 0; j < p.length(); j++)
				{
					if (p[j] == t[pt])
					{
						p[j] = ' ';
						pt++;
						break;
					}
				}
				if (j == p.length())
				{
					flag = 0;
					break;
				}
			}
		}
		if (ps < s.length() || !flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
