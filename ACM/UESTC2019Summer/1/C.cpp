#include<bits/stdc++.h>
using namespace std;

char txt[100001];
char pat[100001];
int nxt[100001];

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
    int n, m, x;
    gets(txt);
    gets(pat);
    cin >> x;
    n = strlen(txt);
    m = strlen(pat);
    getnxt(m);
    int i, j;
    int l = 0, r = m + 1;
    while(l + 1 != r)
    {
        int cnt = 0;
        i = 0, j = 0;
    	while(i < n)
    	{
    		if(txt[i] == pat[j])
    		{
    			i++;
    			j++;
    		}
    		if(j == m)
    		{
    		    cnt++;
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
    	if (cnt < x)
    	{
    	    r = m;
    	    m = (l + r)/2;
    	}
    	else
    	{
    	    l = m;
    	    m = (l + r)/2;
    	}
    }
	if (m == 0)
	{
	    cout << "IMPOSSIBLE";
	}
	else
	{
	   for (int l = 0; l < m; l++)
	   {
	       printf("%c", pat[l]);
	   }
    }	
    return 0;
}
