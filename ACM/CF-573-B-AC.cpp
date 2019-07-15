#include<bits/stdc++.h>
using namespace std;

int main()
{
	char str[3];
	int m = 0, s = 0, p = 0;
	int am[3], as[3], ap[3];
	for (int i = 0; i < 3; i++)
	{
		scanf("%s", str);
		if (str[1] == 'm')
			am[m++] = str[0] - '0';
		if (str[1] == 's')
			as[s++] = str[0] - '0';
		if (str[1] == 'p')
			ap[p++] = str[0] - '0';
	}
	sort(am, am+m);
	sort(as, as+s);
	sort(ap, ap+p);
	if (m < 3 && s < 3 && p < 3)
	{
		if (m == 1 && s == 1 && p == 1)
			cout << "2";
		else
		{
			if (m == 2)
			{
				if (am[1] - am [0] <= 2)
					cout << "1";
				else
					cout << "2";
			}
			else
			{
				if (s == 2)
				{
					if (as[1] - as[0] <= 2)
						cout << "1";
					else
						cout << "2";
				}
				else
				{
					if (ap[1] - ap[0] <= 2)
						cout << "1";
					else
						cout << "2";
				}
			}
		}
	}
	else
	{
		if (m == 3)
		{
			if (am[0] + am[2] == 2 * am[1] && am[2] - am[0] <=2)
			{
				cout << "0";
			}
			else
			{
				if (am[1] - am[0] <= 2 || am[2] - am[1] <= 2)
					cout << "1";
				else
					cout << "2";
			}
		}
		else if (s == 3)
		{
			if (as[0] + as[2] == 2 * as[1] && as[2] - as[0] <= 2)
			{
				cout << "0";
			}
			else
			{
				if (as[1] - as[0] <= 2 || as[2] - as[1] <= 2)
					cout <<  "1";
				else
					cout << "2";
			}
		}
		else
		{
			if (ap[0] + ap[2] == 2 * ap[1] && ap[2] - ap[0] <= 2)
			{
				cout << "0";
			}
			else
			{
				if (ap[1] - ap[0] <= 2 || ap[2] - ap[1] <= 2)
					cout << "1";
				else
					cout << "2";
			}
		}
	}
	return 0;
}
