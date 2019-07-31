#include<bits/stdc++.h>
#define MAXM 4
#define MAXN 4
//差一个大整数类的模板
using namespace std;

const __int128 P = 1125899839733759;

struct mat
{
	__int128 arr[MAXM][MAXN];
	int m, n;
	mat operator = (const mat& a)
	{
		m = a.m;
		n = a.n;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				arr[i][j] = a.arr[i][j];
	}
	mat operator * (const mat& a)
	{
		mat tmp;
		assert(n == a.m);
		tmp.m = m;
		tmp.n = a.n;
		for (int i = 1; i <= tmp.m; i++)
		{
			for (int j = 1; j <= tmp.n; j++)
			{
				__int128 sum = 0;
				for (int k = 1; k <= n; k++)
				{
					sum += (arr[i][k] * a.arr[k][j]) % P;
					sum %= P;
				}
				tmp.arr[i][j] = sum;
			}
		}
		return tmp;
	}
};

__int128 fastmod(__int128 a, __int128 b, __int128 p)
{
	if (a == 0)
		return 0;
	if (b == 0)
		return 1;
	__int128 ans = fastmod(a, b/2, p);
	if (b & 1)
		return ((a*ans)%p * ans)%p;
	else
		return (ans * ans)%p;
}

mat fastmod(mat a, __int128 b, __int128 p)
{
	if (b == 1)
		return a;
	mat ans = fastmod(a, b/2, p);
	if (b & 1)
		return ((a*ans) * ans);
	else
		return (ans * ans);
}

int main()
{
	int t;
	fastmod(2, 2, 3);
	cin >> t;
	while (t--)
	{
		long long n;
		scanf("%lld", &n);
		__int128 up = fastmod(2, (__int128)n, P-1);
		mat A;
		A.m = 2;
		A.n = 2;
		A.arr[1][1] = 1;
		A.arr[1][2] = 1;
		A.arr[2][1] = 1;
		A.arr[2][2] = 0;
		mat An = fastmod(A, up, P);
		mat X0;
		X0.m = 2;
		X0.n = 1;
		X0.arr[1][1] = 1;
		X0.arr[2][1] = 0;
		mat Xn = An * X0;
		printf("%lld\n", (long long)Xn.arr[2][1]);
	}
	return 0;
}
