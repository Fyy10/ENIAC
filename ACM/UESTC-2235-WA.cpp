#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
int a[10000];
int up[10000];
int down[10000];
int dpos[100000];
int n;
//int lmax[10000],rmax[10000];
int findmaxoy()
{
	int i,j,maxoy=0;
	for(i=1;i<=n;i++)
	{
		up[i]=down[i]=1;
		//lmax[i]=rmax[i]=0;
	}
	for(i=2;i<=n;i++)
	{
		for(j=1;j<i;j++)
			if(a[j]<=a[i])
				up[i]=max(up[i],up[j]+1);
		//lmax[i]=max(lmax[i-1],up[i]);
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=n;j>i;j--)
			if(a[j]<=a[i])
				down[i]=max(down[i],down[j]+1);
		//rmax[i]=max(rmax[i+1],down[i]);
	}
	up[0]=up[n+1]=down[0]=down[n+1]=1000000;
	for(i=1;i<=n;i++)
	{
		int tmp=min(up[i],down[i]);
		if(2*tmp-1>maxoy)
			maxoy=2*tmp-1;
	}
	return maxoy/2;
}
int main()				//Wrong on n=4, 1 2 2 1
{
	int i;
	set<int> s;
	while(scanf("%d",&n)==1)
	{
		while(!s.empty())
			s.erase(s.begin());
		int pos=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++)
		{
			if(s.find(a[i])==s.end())
			{
				pos++;
				dpos[a[i]]=pos;
				s.insert(a[i]);
				a[i]=dpos[a[i]];
			}
			else
			{
				a[i]=dpos[a[i]];
			}
		}
		printf("%d\n",findmaxoy());
	}
	return 0;
}
