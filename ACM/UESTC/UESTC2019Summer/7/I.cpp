#include<bits/stdc++.h>
using namespace std;

map<int, string> ma;
map<string, int> ms;

int main()
{
	int t;
	cin >> t;
	ma[1] = "Monday";
	ma[2] = "Tuesday";
	ma[3] = "Wednesday";
	ma[4] = "Thursday";
	ma[0] = "Friday";
	ms["Monday"] = 1;
	ms["Tuesday"] = 2;
	ms["Wednesday"] = 3;
	ms["Thursday"] = 4;
	ms["Friday"] = 0;
	while (t--)
	{
		int y, m, d;
		int y2, m2, d2;
		string day;
		cin >> y >> m >> d >> day;
		cin >> y2 >> m2 >> d2;
		if (d2 < d)
			d2 += 30;
		d2 = d2 + ms[day] - d;
		cout << ma[d2%5] << endl;
	}
	return 0;
}
