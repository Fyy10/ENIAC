#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

struct point
{
    int x;
    int y;
}p[50];

bool pin(point a, int left, int right, int up, int down)
{
    return a.x >= left && a.x <= right && a.y <= up && a.y >= down;
}

int main()
{
    std::multiset<int> msx, msy;
    std::multiset<int>::iterator it;
    int left = 50, right = 0, up = 0, down = 50;
    int n, x, y;
    cin >> n;
    msx.clear();
    msy.clear();
    for (int i = 0; i <= n<<2; i++)
    {
        cin >> x >> y;
        msx.insert(x);
        msy.insert(y);
        p[i].x = x;
        p[i].y = y;
    }
    for (it = msx.begin(); it != msx.end(); it++)
    {
        if (msx.count(*it) > 1)
        {
            if (*it < left)
                left = *it;
            if (*it > right)
                right = *it;
        }
    }
    for (it = msy.begin(); it !=msy.end(); it++)
    {
        if (msy.count(*it) > 1)
        {
            if (*it < down)
                down = *it;
            if (*it > up)
                up = *it;
        }
    }
    for (int i=0; i<= n<<2; i++)
    {
        if((p[i].x > left && p[i].x != right && p[i].y != up && p[i].y != down) || !pin(p[i], left, right, up, down))
            cout << p[i].x << ' ' << p[i].y;
    }
    return 0;
}
