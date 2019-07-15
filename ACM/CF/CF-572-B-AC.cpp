#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    if (a[n-1] >= a[n-2] + a[n-3])
        cout << "NO";
    else
    {
        int i = 0;
        cout << "YES\n";
        while (i < n)
        {
            if (i % 2)
                printf("%d ", a[i]);
            i++;
        }
        i--;
        while (i >= 0)
        {
            if (!(i%2))
                printf("%d ", a[i]);
            i--;
        }
    }
    return 0;
}
