#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[10];
	int n, x;
	memset(a, 0, sizeof(a));
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		string str;
		stringstream ss;
		ss << i;
		ss >> str;
		for (int j = 0; j < str.length(); j++)
		{
			a[str[j]-'0']++;
		}
	}
	cout << a[x];
	return 0;
}
