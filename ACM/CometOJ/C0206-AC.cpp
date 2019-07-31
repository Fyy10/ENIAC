#include<bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	cin >> str;
	if (str[0] == '-')
		printf("-");
	int n = str.length() - 1;
	while (str[n] == '0')
		n--;
	while (n >= 0 && str[n] != '-')
	{
		printf("%c", str[n]);
		n--;
	}
	return 0;
}
