#include<bits/stdc++.h>
using namespace std;

long long a[100000], b[100000];

int main()
{
    int n;
    long long sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    for (int i = 2; i <= n; i+=2)
    {
        sum -= 2*a[i];
    }
    b[1] = (int)sum;
    cout << b[1] << ' ';
    for (int i = 1; i < n; i++)
    {
        b[i+1] = 2*a[i] - b[i];
        printf("%d ", b[i+1]);
    }
    return 0;
}
