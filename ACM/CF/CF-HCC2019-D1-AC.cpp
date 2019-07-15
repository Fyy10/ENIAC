#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, m, t;
    bool flag;
    int pos;
    cin >> n >> k >> m >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> flag >> pos;
        if (flag)
        {
            if (pos <= k)
            {
                k++;
            }
            n++;
        }
        else
        {
            if (pos < k)
            {
                k = k - pos;
                n = n - pos;
            }
            else
            {
                n = pos;
            }
        }
        cout << n << ' ' << k << endl;
    }
    return 0;
}
