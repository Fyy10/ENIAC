#include<stdio.h>
#include<string.h>
#define INF 20000000
int roadlength[101][101];
int n,m;
void Dijkstra(int s);
int dis[101];
int used[101];
void init();
int allused();
int findmin();
int main()
{
	int i,j,a,b,c;
	while(scanf("%d %d",&n,&m)==2)
	{
		if(n==0&&m==0)
			break;
		init();
		while(m--)
		{
			scanf("%d %d %d",&a,&b,&c);
			roadlength[a][b]=c;
			roadlength[b][a]=c;
		}
		Dijkstra(1);
		printf("%d\n",dis[n]);
	}
	return 0;
}
void Dijkstra(int s)
{
	int i,j,mindis,r=s;
	for(i=1;i<=n;++i)
	{
		dis[i]=roadlength[s][i];
	}
	dis[s]=0;
	used[s]=1;
	r=findmin();
	while(!allused())
	{
		for(i=1;i<=n;++i)
		{
			if(i==r||used[i])
				continue;
			if(dis[r]+roadlength[r][i]<dis[i])
			{
				dis[i]=dis[r]+roadlength[r][i];
			}
		}
		r=findmin();
		used[r]=1;
	}
}
void init()
{
	int i,j;
	for(i=1;i<=n;++i)
	{
		roadlength[i][i]=0;
		dis[i]=INF;
		used[i]=0;
		for(j=1;j<=n;++j)
		{
			if(i!=j)
			{
				roadlength[i][j]=INF;
			}
		}
	}
}
int allused()
{
	int i;
	for(i=1;i<=n;++i)
		if(used[i]==0)
			return 0;
	return 1;
}
int findmin()
{
	int i,mind=INF,minx;
	for(i=1;i<=n;++i)
		if(dis[i]<=mind&&!used[i])
		{
			mind=dis[i];
			minx=i;
		}
	return minx; 
}
