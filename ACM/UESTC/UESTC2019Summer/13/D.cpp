#include<bits/stdc++.h>
#define M(x) ((x)%P)
using namespace std;

const long long P = 1e9 + 7;

long long fastmod(long long a, long long b)
{
	assert(a >= 0 && b >= 0);
	if (a == 0)
		return 0;
	if (b == 0)
		return 1;
	long long ans = fastmod(a, b/2);
	if (b & 1)
		return M(a * M(ans * ans));
	else
		return M(ans * ans);
}

int main()
{
	long long n, k;
	cin >> n >> k;
	long long k2 = fastmod(2, k);
	long long ans = M(k2 * M(2 * n - 1));
	if (ans == P - 1)
		ans = 0;
	else
		ans++;
	if (n == 0)
		cout << 0;
	else
		cout << ans;
	return 0;
}
