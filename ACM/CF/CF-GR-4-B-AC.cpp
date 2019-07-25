#include<bits/stdc++.h>
using namespace std;

int cnt[1000000];
int pre[1000000];
int suf[1000000];

int main()
{
	char c;
	int cntw = 0;
	int cnto = 0;
	int p = 0;
	int vfirst = 0;
	while ((c = getchar()) != '\n')
	{
		if (c == 'v')
		{
			if (cnto)
				cnt[p++] = cnto;
			if (!vfirst && p == 0)
				vfirst = 1;
			cnto = 0;
			cntw++;
		}
		if (c == 'o')
		{
			if (cntw)
				cnt[p++] = cntw - 1;
			cntw = 0;
			cnto++;
		}
	}
	if (cnto)
		cnt[p++] = cnto;
	if (cntw)
		cnt[p++] = cntw - 1;
	long long ans = 0;
	if (vfirst)
	{
		pre[0] = cnt[0];
		suf[(p-1)/2*2] = cnt[(p-1)/2*2];
		for (int i = 2; i < p; i++)
		{
			if ((i%2) == 0)
				pre[i] = pre[i-2] + cnt[i];
		}
		for (int i = p-1; i >= 0; i--)
		{
			if ((i%2) == 0)
				suf[i] = suf[i+2] + cnt[i];
		}
		for (int i = 1; i < p - 1; i += 2)
			ans += (long long)pre[i-1] * (long long)cnt[i] * (long long)suf[i+1];
	}
	else
	{
		pre[1] = cnt[1];
		suf[(p-1)/2*2+1] = cnt[(p-1)/2*2+1];
		for (int i = 3; i < p; i++)
		{
			if (i%2)
				pre[i] = pre[i-2] + cnt[i];
		}
		for (int i = p-1; i >= 0; i--)
		{
			if (i%2)
				suf[i] = suf[i+2] + cnt[i];
		}
		for (int i = 2; i < p - 2; i += 2)
			ans += (long long)pre[i-1] * (long long)cnt[i] * (long long)suf[i+1];
	}
	cout << ans;
	return 0;
}
