#include<bits/stdc++.h>
using namespace std;

struct party
{
	int num;
	int val;
}a[100];

bool cmp(const party& a, const party& b)
{
	return a.val < b.val;
}

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].val;
		a[i].num = i + 1;
		sum += a[i].val;
	}
	sort(a+1, a+n, cmp);
	if (a[0].val > sum/2)
	{
		printf("1\n%d", a[0].num);
		return 0;
	}
	int presum[100];
	presum[0] = a[0].val;
	for (int i = 1; i < n; i++)
		presum[i] = presum[i-1] + a[i].val;
	int idx = upper_bound(presum+1, presum+n, sum/2) - presum;
	if (idx == n || a[idx].val > a[0].val/2)
		printf("0");
	else
	{
		printf("%d\n%d ", idx + 1, a[0].num);
		for (int i = 1; i <= idx; i++)
			printf("%d ", a[i].num);
	}
	return 0;
}
