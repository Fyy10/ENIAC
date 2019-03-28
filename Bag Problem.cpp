#include<stdio.h>
#include<string.h>
#define ITEMN 10
#define VAL_WEIGHT 3
#define TOTWEIGHT 1000
int memval[ITEMN][TOTWEIGHT];
int bags[ITEMN][VAL_WEIGHT];
int calval(int itemn,int weightleft);
int max(int a,int b);
int main()
{
	int i,n,w;
	scanf("%d %d",&n,&w);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&bags[i][1],&bags[i][2]);
	}
	memset(memval,-1,sizeof(memval));
	printf("%d\n",calval(n,w));
	return 0;
}
int calval(int itemn,int weightleft)
{
	int ans=0;
	if(memval[itemn][weightleft]!=-1)
		return memval[itemn][weightleft];
	if(itemn==1)
	{
		if(weightleft>=bags[itemn][2])
		{
			ans+=bags[itemn][1];
		}
	}
	else
	{
		ans+=max(calval(itemn-1,weightleft),(calval(itemn-1,weightleft-bags[itemn][2])+bags[itemn][1]));
	}
	memval[itemn][weightleft]=ans;
	return ans;
}
int max(int a,int b)
{
	return a>b?a:b;
}
