#include<stdio.h>
char a[200][200];
int main()
{
	int n,m,i,j,h,x,y,s,bias=15;
	while(scanf("%d %d",&m,&n)==2)
	{
		for(i=bias-1;i<=m+bias;i++)
			for(j=bias-1;j<=m+bias;j++)
				a[i][j]=46;
		for(i=0;i<n;i++)
		{
			scanf("%d %d %d",&s,&x,&y);
			if(x>=1-bias&&x<m+bias&&y>=1-bias&&y<m+bias)
			{
				x+=bias;
				y+=bias;
				if(s==0)
				{
					a[x][y]=111;
					a[x-1][y]=a[x+1][y]=95;
				}
				else
				{
					a[x][y]=124;
					a[x-1][y]=a[x+1][y]=95;
					for(h=1;h<=s;h++)
					{
						a[x][y+h]=124;
						a[x-1][y+h]=47;
						a[x+1][y+h]=92;
					}
					a[x][y+s+1]=94;
				}
			}
		}
		for(i=bias-1;i<=m+bias;i++)
			a[bias-1][i]=a[m+bias][i]=a[i][bias-1]=a[i][m+bias]=42;
		for(j=m+bias;j>=bias-1;j--)
		{
			for(i=bias-1;i<=m+bias;i++)
				printf("%c",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
