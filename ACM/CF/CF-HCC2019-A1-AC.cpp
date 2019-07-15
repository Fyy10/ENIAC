#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long r;
    cin >> r;
    if (r%2 && r>=5)
    {
        long long tmp = (r-3)>>1;
        cout << '1' << ' ' << tmp;
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
