#include<bits/stdc++.h>
using namespace std;

int a[100000];

int main()
{
    int t;
    int n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        long long ans = 0;
        int l = 0, r = 2*m - 1;
        while (m--)
        {
            ans += (long long)a[l] * (long long)a[r];
            l++;
            r--;
        }
        cout << ans << endl;
    }
    return 0;
}
