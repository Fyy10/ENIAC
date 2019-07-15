#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    x -= (y-1);
    if (y < 1)
        cout << "NO";
    else
    {
        if (x < 0 || x % 2)
            cout << "NO";
        else
        {
            if (y == 1 && x > 0)
                cout << "NO";
            else
                cout << "YES";
        }
    }
    return 0;
}
