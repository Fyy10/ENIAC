#include<iostream>
#include<cstring>
using namespace std;

char txt[1000001];
char pat[1000001];
int nxt[1000001];

void getnxt(int m)
{
	int len = 0;
	nxt[0] = 0;
	int i = 1;
	while(i < m)
	{
		if(pat[i] == pat[len])
		{
			len++;
			nxt[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
				len = nxt[len-1];
			else
			{
				nxt[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
	scanf("%s", txt);
	getchar();
	scanf("%s", pat);
	int n = strlen(txt), m = strlen(pat);
	getnxt(m);
	int i = 0, j = 0;
	while(i < n)
	{
		if(txt[i] == pat[j])
		{
			i++;
			j++;
		}
		if(j == m)
		{
			cout << i-m+1 << '\n';
			j = nxt[j-1];
		}
		else
		{
			if(i < n && txt[i] != pat[j])
			{
				if(j != 0)
					j = nxt[j-1];
				else
					i++;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		cout << nxt[i] << ' ';
	}
	return 0;
}
