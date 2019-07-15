#include<bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
    int t;
    LL n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (n == 2 && k == 3)
        {
            cout << "NO\n";
            continue;
        }
        if (n > 30 || k <= (((LL)1<<(2*n)) - 1)/3)
        {
            LL ans = n;
            k--;
            ans--;
            LL q;
            LL sum = 1;
            for (q = 1; q < n; q++)
            {
                sum += (LL)1<<q;
                k -= sum;
                if (k < 0)
                    break;
            }
            ans -= q;
            ans++;
            cout << "YES " << ans << endl;
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
