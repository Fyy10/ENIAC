#include<stdio.h>
#define MAXN 101
#define INF 2000000
int road[MAXN][MAXN];
int n,m;
void init();
void Floyd();
int main()
{
	int a,b,tmp;
	while(scanf("%d %d",&n,&m)==2)
	{
		if(n==0&&m==0)
			break;
		init();
		while(m--)
		{
			scanf("%d %d %d",&a,&b,&tmp);
			road[a][b]=tmp;
			road[b][a]=tmp;
		}
		Floyd();
		printf("%d\n",road[1][n]);
	}
	return 0;
}
void init()
{
	int i,j;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
		{
			if(i==j)
				road[i][j]=0;
			else
				road[i][j]=INF;
		}
}
void Floyd()
{
	int i,j,k;
	for(k=1;k<=n;++k)
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
			{
				if(road[i][k]+road[k][j]<road[i][j])
					road[i][j]=road[i][k]+road[k][j];
			}
}
