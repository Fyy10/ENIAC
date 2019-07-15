#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l, r, minr = 2019;
    cin >> l >> r;
    if (r - l >= 2019)
        minr = 0;
    l %= 2019;
    r %= 2019;
    if (l > r)
    {
        int t = r;
        r = l;
        l = t;
    }
    if (l == r)
        minr = 0;
    for (int i = l; i <= r; i++)
    {
        for (int j = i+1; j <= r; j++)
        {
            if ((i*j)%2019 < minr)
            {
                minr = (i*j) % 2019;
            }
        }
    }
    cout << minr;
    return 0;
}
