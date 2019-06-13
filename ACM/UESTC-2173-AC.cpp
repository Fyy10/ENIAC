#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<math.h>
using namespace std;
struct city
{
	int x;
	int y;
}cities[18]; 
int dist[18][18];
void init();
int n;
long long dp[18][1<<17];
int main()
{
	int s,i,j,st;
	scanf("%d %d",&n,&s);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&cities[i].x,&cities[i].y);
	}
	init();
	for(i=1;i<=n;i++)
	{
		for(j=0;j<(1<<n);j++)
		{
			dp[i][j]=LLONG_MAX/2;
		}
	}
	dp[s][1<<(s-1)]=0;
	for(st=1<<(s-1);st<(1<<n);st++)
	{
		for(i=1;i<=n;i++)
			if(st&(1<<(i-1)))
			{
				for(j=1;j<=n;j++)
				{
					if(!(st&(1<<(j-1))))
						dp[j][st|(1<<(j-1))]=min(dp[j][st|(1<<(j-1))],dp[i][st]+dist[i][j]);
				}
			}
	}
	st--;
	long long minn=LLONG_MAX/2;
	for(i=1;i<=n;i++)
	{
		if(dp[i][st]<minn&&i!=s)
			minn=dp[i][st];
	}
	printf("%lld",minn);
	return 0;
}
void init()
{
	int i,j;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
		{
			dist[i][j]=dist[j][i]=abs(cities[i].x-cities[j].x)+abs(cities[i].y-cities[j].y);
		}
}
