#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, l, r;
    int a[100001];
    int sum[100001];
    cin >> n;
    a[0] = 0;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", (sum[r] - sum[l-1])/10);
    }
    return 0;
}
