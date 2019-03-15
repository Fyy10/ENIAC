#include<stdio.h>
#include<string.h>
#define N 32
struct point
{
	int m;
	int n;
}pos;
int a[N][N];
void printa(int n);
int main()
{
	int n,total=1;
	char state='d';
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	pos.m=1;
	pos.n=n;
	a[pos.m][pos.n]=total;
	while(total<n*n)
	{
		switch(state)
		{
			case 'd':
			{
				if(pos.m+1<=n&&!a[pos.m+1][pos.n])
				{
					++total;
					++pos.m;
					a[pos.m][pos.n]=total;
				}
				else
					state='l';
				break;
			}
			case 'l':
			{
				if(pos.n-1>=1&&!a[pos.m][pos.n-1])
				{
					++total;
					--pos.n;
					a[pos.m][pos.n]=total;
				}
				else
					state='u';
				break;
			}
			case 'u':
			{
				if(pos.m-1>=1&&!a[pos.m-1][pos.n])
				{
					++total;
					--pos.m;
					a[pos.m][pos.n]=total;
				}
				else
					state='r';
				break;
			}
			case 'r':
			{
				if(pos.n+1<=n&&!a[pos.m][pos.n+1])
				{
					++total;
					++pos.n;
					a[pos.m][pos.n]=total;
				}
				else
					state='d';
				break;
			}
			default:printf("Error\n");
		}
	}
	printa(n);
	return 0;
}
void printa(int n)
{
	int x,y;
	for(x=1;x<=n;++x)
		for(y=1;y<=n;++y)
		{
			if(y<n)
				printf("%3d ",a[x][y]);
			else
				printf("%3d\n",a[x][y]);
		}
}
