#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s[15];
	cin >> s;
	int n = strlen(s);
	int fac = 1;
	int num = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (s[i] <= '9' && s[i] >= '0')
		{
			num += fac * (s[i] - '0');
			fac++;
		}
	}
	num %= 11;
	char c;
	if (num == 10)
		c = 'X';
	else
		c = num + '0';
	if (s[n-1] == c)
		cout << "Right";
	else
	{
		s[n-1] = c;
		cout << s;
	}
	return 0;
}
