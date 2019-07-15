#include<stdio.h>
#include<string.h>
#include<set>
#include<algorithm>
using namespace std;
struct edge
{
	int w;
	int n1;
	int n2;
}a[500000];
bool cmp(const edge a,const edge b)
{
	return a.w<b.w;
}
bool used[1001][1001];
int father[1001];
int find(int x){return (father[x]<0)?x:(father[x]=find(father[x]));}

int main()
{
	int n,m,k,i,j,count;
	long long ans=0;
	memset(father,-1,sizeof(father));
	memset(used,0,sizeof(used));
	scanf("%d %d %d",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&a[i].n1,&a[i].n2,&a[i].w);
	}
	count=n;
	sort(a,a+m,cmp);
	for(i=0;i<m;i++)
	{
		int r1=find(a[i].n1),r2=find(a[i].n2);
		if(used[a[i].n1][a[i].n2]==0&&r1!=r2)
		{
			count--;
			ans+=(long long)a[i].w;
			used[a[i].n1][a[i].n2]=used[a[i].n2][a[i].n1]=1;
			father[r2]=r1;
		}
		if(count==k)
			break;
	}
	printf("%lld",ans);
	return 0;
}
