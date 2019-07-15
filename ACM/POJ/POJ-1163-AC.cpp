#include<stdio.h>
#include<string.h>
//int maxsum(int a,int b);
int maxa(int a1,int a2);
//int memsum[101][101];
int tri[101][101];
int n;
int main()
{
	int i,j;
	//memset(memsum,-1,sizeof(memsum));
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=i;++j)
			scanf("%d",&tri[i][j]);
	}
	for(i=n-1;i>=1;--i)
	{
		for(j=1;j<=i;++j)
			tri[i][j]=maxa(tri[i+1][j],tri[i+1][j+1])+tri[i][j];
	}
	printf("%d\n",tri[1][1]);
	return 0;
}
/*int maxsum(int a,int b)
{
	if(a==n)
	{
		memsum[a][b]=tri[a][b];
	}
	else
	{
		if(memsum[a][b]==-1)
			memsum[a][b]=maxa(maxsum(a+1,b),maxsum(a+1,b+1))+tri[a][b];
	}
	return memsum[a][b];
}*/
int maxa(int a1,int a2)
{
	return a1>a2?a1:a2;
}
