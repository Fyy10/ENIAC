#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool a[100];
    int n;
    int n1=0, n0=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        scanf("%1d",&a[i]);
        if(a[i])
            n1++;
        else
            n0++;
    }
    if(n1 != n0)
    {
        cout << "1\n";
        for(int i=0;i<n;i++)
            cout << a[i];
    }
    else
    {
        cout << "2\n";
        cout << a[0] << ' ';
        for(int i=1;i<n;i++)
            cout << a[i];
        cout << ' ';
    }
    return 0;
}
