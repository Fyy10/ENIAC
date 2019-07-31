#include<bits/stdc++.h>
using namespace std;

char pat[20];
char txt[1000010];
char tmp[1000010];

int main()
{
	pat[0] = txt[0] = ' ';
	pat[1] = txt[1] = '\0';
	scanf("%s", tmp);
	strcat(pat, tmp);
	gets(tmp);
	strcat(txt, tmp);
	int m = strlen(pat);
	int n = strlen(txt);
	pat[m++] = ' ';
	pat[m] = '\0';
	txt[n++] = ' ';
	txt[n] = '\0';
	int pos = -1;
	int cnt = 0;
	int cw = -1;
	for (int i = 0; i < n; i++)
	{
		if (txt[i] <= 'Z' && txt[i] >= 'A')
			txt[i] += 'a' - 'A';
	}
	for (int i = 0; i < m; i++)
	{
		if (pat[i] <= 'Z' && pat[i] >= 'A')
			pat[i] += 'a' - 'A';
	}
	for (int i = 0; i <= n-m; i++)
	{
		if (txt[i] == ' ')
			cw++;
		for (int j = 0; j < m; j++)
		{
			if (pat[j] != txt[i+j])
				break;
			if (j == m-1)
			{
				if (pos < 0)
					pos = cw;
				cnt++;
			}
		}
	}
	if (pos >= 0)
		cout << cnt << " " << pos;
	else
		cout << pos;
	cout << pat << endl;
	cout << txt << endl;
	return 0;
}
