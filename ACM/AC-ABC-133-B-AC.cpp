#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, d, ans = 0;
    cin >> n >> d;
    int a[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k < d; k++)
            {
                sum += (a[i][k] - a[j][k]) * (a[i][k]-a[j][k]);
            }
            int dist = sqrt(sum);
            if (dist*dist == sum)
                ans++;
        }
    }
    cout << ans;
    return 0;
}
