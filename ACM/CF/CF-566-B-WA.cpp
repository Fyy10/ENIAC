#include<bits/stdc++.h>
using namespace std;

char board[501][501];

int main()
{
	int h, w;
	cin >> h >> w;
	int i, j;
	int cnt=0;
	for(i=0;i<h;i++)
	{
		getchar();
		scanf("%s",board[i]);
	}
	for(i=1;i<h-1;i++)
	{
		for(j=1;j<w-1;j++)
		{
			if(board[i][j] == '*' && board[i-1][j] == '*' && board[i+1][j] == '*' && board[i][j-1] == '*' && board[i][j+1] == '*')
			{
				cnt++;
				board[i][j] = '.';
				for(int k=i-1;k>=0&&board[k][j]=='*';k--)
				{
					board[k][j] = '.';
				}
				for(int k=i+1;k<w&&board[k][j]=='*';k++)
				{
					board[k][j] = '.';
				}
				for(int k=j-1;k>=0&&board[i][k]=='*';k--)
				{
					board[i][k] = '.';
				}
				for(int k=i+1;k<h&&board[i][k]=='*';k++)
				{
					board[i][k] = '.';
				}
			}
		}
	}
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
			if(board[i][j] == '*')
				cnt=0;
	}
	if(cnt == 1)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
