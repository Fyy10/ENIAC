#include<bits/stdc++.h>
using namespace std;

char rev[]="123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ5YXWVUT2   O MJ LIH  3   A 8  Z ES1";

int main()
{
	char strin[1001];
	int judger;
	int t;
	cin >> t;
	int l = strlen(rev);
	while (t--)
	{
		scanf("%s", strin);
		judger = 1;
		int ns = strlen(strin);
		for(int i = 0;i < ns; i++)
		{
			int j;
			for(j = 0; strin[i] != rev[j]; j++);
			if (!judger)
				continue;
			if(strin[ns-i-1]!=rev[l-j-1])
			{
				judger=0;
				break;
			}
		}
		if (judger)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
