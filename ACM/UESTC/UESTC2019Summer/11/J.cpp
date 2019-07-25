#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		int n, m;
		scanf("%d %d", &n, &m);
		bool flag = false;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			if (a == 1 && b == n)
				flag = true;
		}
		if (flag)
			cout << "Jorah Mormont\n";
		else
			cout << "Khal Drogo\n";
	}
	return 0;
}
