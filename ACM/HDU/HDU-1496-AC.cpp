#include<stdio.h>
#include<string.h>
int value[2000001];
int sq[101];
int main()
{
	int i,j,a,b,c,d,ans;
	for(i=1;i<=100;i++)
	{
		sq[i]=i*i;
	}
	while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)
	{
		if((a>0&&b>0&&c>0&&d>0)||(a<0&&b<0&&c<0&&d<0))
		{
			printf("%d\n",0);
			continue;
		}
		ans=0;
		memset(value,0,sizeof(value));
		for(i=1;i<=100;i++)
			for(j=1;j<=100;j++)
				value[a*sq[i]+b*sq[j]+1000000]++;
		for(i=1;i<=100;i++)
			for(j=1;j<=100;j++)
			{
				ans+=value[-(c*sq[i]+d*sq[j])+1000000];
			}
		ans*=16;
		printf("%d\n",ans);
	}
	return 0;
}
