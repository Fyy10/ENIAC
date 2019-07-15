#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[101],sum[101];
	int n;
	sum[0]=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		sum[i] = a[i]+sum[i-1];
	}
	int minval=0x3f;
	for(int i=1;i<n;i++)
	{
		int tmp=abs(sum[i]-sum[0]-(sum[n]-sum[i]));
		if(tmp<minval)
			minval = tmp;
	}
	cout << minval;
	return 0;
}
