#include<stdio.h>
#include<string.h>
#define MINEN 100
#define MONEY_WORKER 3
#define WORKERN 1000
//int minearr[MINEN];
int mine[MINEN][MONEY_WORKER];
int memmoney[MINEN][WORKERN];
int money(int minen,int workerleft);
int max(int a,int b);
int main()
{
	int i,n,w;
	scanf("%d %d",&n,&w);
	for(i=1;i<=n;++i)
	{
		scanf("%d %d",&mine[i][1],&mine[i][2]);
	}
	memset(memmoney,-1,sizeof(memmoney));
	printf("%d\n",money(n,w));
	/*for(i=1;i<=n;++i)
	{
		if(i==n)
			printf("%d\n",minearr[i]);
		else
			printf("%d ",minearr[i]);
	}*/
	return 0;
}
int money(int minen,int workerleft)
{
	int ans=0;
	if(memmoney[minen][workerleft]!=-1)
		return memmoney[minen][workerleft];
	if(minen==1)
	{
		if(workerleft>=mine[minen][2])
		{
			ans+=mine[minen][1];
			//memmoney[minen][workerleft]=ans;
			//minearr[minen]=1;
		}
		else
		{
			//memmoney[minen][workerleft]=ans;
			//minearr[minen]=0;
		}
	}
	else
	{
		if(workerleft>=mine[minen][2]&&(money(minen-1,workerleft-mine[minen][2])+mine[minen][1])>money(minen-1,workerleft))
		{
			ans+=money(minen-1,workerleft-mine[minen][2])+mine[minen][1];
			//memmoney[minen][workerleft]=ans;
			//minearr[minen]=1;
		}
		else
		{
			ans+=money(minen-1,workerleft);
			//memmoney[minen][workerleft]=ans;
			//minearr[minen]=0;
		}
	}
	memmoney[minen][workerleft]=ans;
	return ans;
}
int max(int a,int b)
{
	return a>b?a:b;
}
