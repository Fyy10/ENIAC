#include<bits/stdc++.h>
#define mul(a,b) ((a%P)*(b%P))%P
using namespace std;

const long long P = 1e9+7;

int main()
{
    long long n;
    long long ans=1;
    cin >> n;
    if (n > 0)
    {
        n = 2*n+1;
        ans += 6*mul(n,n);
        ans %= P;
        ans -= 12*n;
        ans %= P;
        if(ans < P)
            ans += P;
        ans += 8;
        ans %=P;
    }
    cout << ans;
    return 0;
}
