#include<bits/stdc++.h>
#define LL long long
using namespace std;

struct point
{
    int x;
    int y;
}p[300000];

LL dist(point a, point b)
{
    return (LL)abs(a.x - b.x) + (LL)abs(a.y - b.y);
}

LL dp[300001];

int main()
{
    int n;
    int left = 100000000, right = -100000000, up = -100000000, down = 100000000;
    int pl, pr, pu, pd;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &p[i].x, &p[i].y);
        if (p[i].x < left)
        {
            left = p[i].x;
            pl = i;
        }
        if (p[i].x > right)
        {
            right = p[i].x;
            pr = i;
        }
        if (p[i].y < down)
        {
            down = p[i].y;
            pd = i;
        }
        if (p[i].y > up)
        {
            up = p[i].y;
            pu = i;
        }
    }
    for (int k = 3; k <= n; k++)
    {
        if (k == 3)
        {
            LL ans = 0;
            LL tmp = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == pu || j == pl)
                    continue;
                tmp = dist(p[j], p[pu]) + dist(p[j], p[pl]) + dist(p[pu], p[pl]);
                if (tmp > ans)
                    ans = tmp;
            }
            for (int j = 0; j < n; j++)
            {
                if (j == pd || j == pl)
                    continue;
                tmp = dist(p[j], p[pd]) + dist(p[j], p[pl]) + dist(p[pd], p[pl]);
                if (tmp > ans)
                    ans = tmp;
            }
            for (int j = 0; j < n; j++)
            {
                if (j == pu || j == pr)
                    continue;
                tmp = dist(p[j], p[pu]) + dist(p[j], p[pr]) + dist(p[pu], p[pr]);
                if (tmp > ans)
                    ans = tmp;
            }
            for (int j = 0; j < n; j++)
            {
                if (j == pd || j == pr)
                    continue;
                tmp = dist(p[j], p[pd]) + dist(p[j], p[pr]) + dist(p[pd], p[pr]);
                if (tmp > ans)
                    ans = tmp;
            }
            cout << ans << " ";
        }
        else
        {
            cout << ((LL)(right - left + up - down)<<1) << " ";
        }
    }
    return 0;
}
