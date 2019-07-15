#include<stdio.h>
int judge(int floor[][50],int m,int n);
int findgap(int floor[][50],int n);
int main()
{
	int floor[50][50],n,i,j;
	char tmp;
	scanf("%d",&n);
	getchar();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%c",&tmp);
			if(tmp=='#')
				floor[i][j]=1;
			if(tmp=='.')
				floor[i][j]=0;
			if(j==n-1)
				getchar();
		}
	}
	for(i=1;i<n-1;i++)
	{
		for(j=1;j<n-1;j++)
		{
			if(judge(floor,i,j))
			{
				floor[i][j]=1;
				floor[i-1][j]=1;
				floor[i][j-1]=1;
				floor[i][j+1]=1;
				floor[i+1][j]=1;
			}
		}
	}
	if(findgap(floor,n))
		printf("NO");
	else
		printf("YES");
	return 0;
}
int judge(int floor[][50],int m,int n)
{
	if(floor[m][n])
		return 0;
	if(floor[m-1][n])
		return 0;
	if(floor[m][n-1])
		return 0;
	if(floor[m][n+1])
		return 0;
	if(floor[m+1][n])
		return 0;
	return 1;
}
int findgap(int floor[][50],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(floor[i][j]==0)
				return 1;
	return 0;
}
