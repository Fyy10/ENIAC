#include<stdio.h>
#include<string.h>
using namespace std;
int an[1000][1000];
int main()
{
	int n,a,b,g,k,x,y,i,j,l;
	memset(an,0,sizeof(an));
	scanf("%d",&n);
	for(l=1;l<=n;++l)
	{
		scanf("%d %d %d %d",&a,&b,&g,&k);
		for(i=a;i<=g;++i)
			for(j=b;j<=k;++j)
				an[i][j]=l;
	}
	scanf("%d %d",&x,&y);
	if(an[x][y]==0)
		printf("%d\n",-1);
	else
		printf("%d\n",an[x][y]);
	return 0;
}
