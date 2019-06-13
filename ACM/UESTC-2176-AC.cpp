#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000001];
int up[1000001];
int down[1000001];
int uph[1000001];
int downh[1000001];
int main()
{
	int n,i,j,maxoy=0,lup=1,ldown=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		up[i]=down[i]=1;
	}
	uph[1]=a[1];
	downh[1]=a[n];
	for(i=2;i<=n;i++)
	{
		if(a[i]>uph[lup])
		{
			lup++;
			uph[lup]=a[i];
		}
		else
		{
			int *p=lower_bound(uph+1,uph+1+lup,a[i]);
			*p=a[i];
			int pj=p-uph-1;
			up[i]=max(up[i],pj+1);
		}
		int *p=lower_bound(uph+1,uph+1+lup,a[i]);
		int pj=p-uph-1;
		up[i]=max(up[i],pj+1);
	}
	for(i=n-1;i>=1;i--)
	{
		if(a[i]>downh[ldown])
		{
			ldown++;
			downh[ldown]=a[i];
		}
		else
		{
			int *p=lower_bound(downh+1,downh+1+ldown,a[i]);
			*p=a[i];
			int pj=p-downh-1;
			down[i]=max(down[i],pj+1);
		}
		int *p=lower_bound(downh+1,downh+1+ldown,a[i]);
		int pj=p-downh-1;
		down[i]=max(down[i],pj+1);
	}
	for(i=1;i<=n;i++)
	{
		int tmp=min(up[i],down[i]);
		if(2*tmp-1>maxoy)
			maxoy=2*tmp-1;
	}
	printf("%d",maxoy);
	return 0;
}
