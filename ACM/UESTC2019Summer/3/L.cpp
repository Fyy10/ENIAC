#include<bits/stdc++.h>
using namespace std;

long long sum[200001];

int main()
{
    int n, m;
    cin >> n >> m;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        long long tmp;
        scanf("%lld", &tmp);
        sum[i] = tmp + sum[i-1];
    }
    for (int i = 1; i <= m; i++)
    {
        long long tmp;
        scanf("%lld", &tmp);
        long long idx = lower_bound(sum+1, sum+n+1, tmp) - sum;
        printf("%lld %lld\n", idx, tmp - sum[idx-1]);
    }
    return 0;
}
