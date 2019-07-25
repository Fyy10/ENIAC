#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	char s[101];
	scanf("%s", s);
	int ans = 0;
	for (int i = n-1; i >= 0; i--)
	{
		if (i & i)
		{
			int l = (i + 1) / 2;
			int j;
			for (j = 0; j < l; j++)
				if (s[j] != s[j+l])
					break;
			if (j == l)
			{
				ans = l + 1;
				break;
			}
		}
	}
	if (ans)
		ans += n - 2 * (ans - 1);
	else
		ans = n;
	cout << ans;
	return 0;
}
