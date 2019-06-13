#include<stdio.h>
#include<string.h>
#define N 500000
int hash[1000001];
int main()
{
	int m,n,tmp,i,p;
	while(scanf("%d %d",&n,&m)==2)
	{
		memset(hash,0,sizeof(hash));
		p=1000000;
		i=0;
		while(n--)
		{
			scanf("%d",&tmp);
			++hash[tmp+N];
		}
		while(i<m&&p>=0)
		{
			if(hash[p])
			{
				printf("%d ",p-N);
				--hash[p];
				++i;
			}
			else
				--p;
		}
		printf("\n");
	}
	return 0;
}
