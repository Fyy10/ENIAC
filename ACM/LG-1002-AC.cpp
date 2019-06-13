#include<stdio.h>
#include<string.h>
void horse(int board[][30],int nh,int mh);
long long dp(int board[][30],int n,int m);
long long dpmem[30][30];
int main()
{
	int board[30][30],n,m,nh,mh;
	scanf("%d %d %d %d",&n,&m,&nh,&mh);
	memset(dpmem,-1,sizeof(dpmem));
	memset(board,0,sizeof(board));
	horse(board,nh,mh);
	printf("%lld",dp(board,n,m));
	return 0;
}
void horse(int board[][30],int nh,int mh)
{
	board[nh][mh]=1;
	board[nh+2][mh+1]=1;
	board[nh+1][mh+2]=1;
	if(nh-1>=0)
	{
		board[nh-1][mh+2]=1;
		if(mh-2>=0)
			board[nh-1][mh-2]=1;
		if(nh-2>=0)
		{
			board[nh-2][mh+1]=1;
			if(mh-1>=0)
				board[nh-2][mh-1]=1;
		}
	}
	if(mh-1>=0)
	{
		board[nh+2][mh-1]=1;
		if(nh-2>=0)
			board[nh-2][mh-1]=1;
		if(mh-2>=0)
		{
			board[nh+1][mh-2]=1;
			if(nh-1>=0)
				board[nh-1][mh-2]=1;
		}
	}
}
long long dp(int board[][30],int n,int m)
{
	if(dpmem[n][m]>=0)
		return dpmem[n][m];
	if(n==0&&m==0)
	{
		dpmem[n][m]=1;
		return dpmem[n][m];
	}
	if(n==0)
	{
		if(board[n][m-1])
			dpmem[n][m]=0;
		else
			dpmem[n][m]=dp(board,n,m-1);
		return dpmem[n][m];
	}
	if(m==0)
	{
		if(board[n-1][m])
			dpmem[n][m]=0;
		else
			dpmem[n][m]=dp(board,n-1,m);
		return dpmem[n][m];
	}
	if(board[n-1][m])
	{
		if(board[n][m-1])
		{
			dpmem[n][m]=0;
			return dpmem[n][m];
		}
		else
		{
			dpmem[n][m]=dp(board,n,m-1);
			return dpmem[n][m];
		}
	}
	else
	{
		if(board[n][m-1])
		{
			dpmem[n][m]=dp(board,n-1,m);
			return dpmem[n][m];
		}
		else
		{
			dpmem[n][m]=dp(board,n-1,m)+dp(board,n,m-1);
			return dpmem[n][m];
		}
	}
}
