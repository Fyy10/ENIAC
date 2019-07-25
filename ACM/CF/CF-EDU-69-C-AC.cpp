#include<bits/stdc++.h>
using namespace std;

int a[300000];
int diff[300000];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n-1; i++)
		diff[i] = a[i+1] - a[i];
	sort(diff, diff+n-1);
	int ans = 0;
	for (int i = 0; i < n-k; i++)
		ans += diff[i];
	cout << ans;
	return 0;
}
