#include<bits/stdc++.h>
using namespace std;

struct node
{
	long long pos;
	int flag;
}line[400001];

long long cnt[200002];

bool cmp(const node& a, const node& b)
{
	return a.pos < b.pos;
}

int main()
{
	int n;
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long l, r;
		scanf("%lld %lld", &l, &r);
		line[i<<1].pos = l;
		line[i<<1|1].pos = r + 1;
		line[i<<1].flag = 1;
		line[i<<1|1].flag = -1;
	}
	sort(line, line+2*n, cmp);
	int num = 0;
	for (int i = 0; i < 2*n; i++)
	{
		num += line[i].flag;
		if (line[i].flag == 1)
		{
			cnt[num-1] += line[i].pos;
			cnt[num] -= line[i].pos;
		}
		else
		{
			cnt[num+1] += line[i].pos;
			cnt[num] -= line[i].pos;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%lld ", cnt[i]);
	}
	return 0;
}
