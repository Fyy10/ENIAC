#include<stdio.h>
#include<string.h>

int dpmin[101][101];
int dpmax[101][101];

int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}

int main()
{
	int n,maxans=0,minans=0x3f;
	int a[201],sum[201];
	scanf("%d",&n);
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(int i=1;i<=2*n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int bias=0;bias<n;bias++)
	{
		memset(dpmin,0x3f,sizeof(dpmin));
		memset(dpmax,0,sizeof(dpmax));
		for(int i=1;i<=n;i++)
			dpmax[i][i]=dpmin[i][i]=0;
		for(int len=2;len<=n;len++)
		{
			for(int i=1+bias;i<=n-len+1+bias;i++)
			{
				int j=i+len-1;
				for(int k=i;k<j;k++)
				{
					dpmin[i-bias][j-bias]=min(dpmin[i-bias][j-bias],dpmin[i-bias][k-bias]+dpmin[k+1-bias][j-bias]+sum[j]-sum[i-1]);
					dpmax[i-bias][j-bias]=max(dpmax[i-bias][j-bias],dpmax[i-bias][k-bias]+dpmax[k+1-bias][j-bias]+sum[j]-sum[i-1]);
				}
			}
		}
		if(dpmin[1][n]<minans)
			minans=dpmin[1][n];
		if(dpmax[1][n]>maxans)
			maxans=dpmax[1][n];
	}
	printf("%d\n%d",minans,maxans);
	return 0;
}
