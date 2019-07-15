#include<iostream>
#include<algorithm>
#include<set>
#define int long long
using namespace std;

int b[100000];
set<int> d;
set<int>::iterator it;

signed main()
{
    int n;
    int left[3], right[3];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &b[i]);
    }
    if (n <= 2)
        cout << "0";
    else
    {
        left[0] = b[0]-1, left[1] = b[0], left[2] = b[0]+1, right[0] = b[n-1]-1, right[1] = b[n-1], right[2] = b[n-1]+1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                d.insert((right[j]-left[i]) / (n-1));
                d.insert((right[j]-left[i]) / (n-1) + 1);
                d.insert((right[j]-left[i]) / (n-1) - 1);
                d.insert((right[j]-left[i]) / (n-1) + 2);
                d.insert((right[j]-left[i]) / (n-1) - 2);
            }
        }
        int ans = 100001;
        for (it = d.begin(); it != d.end(); it++)
        {
            long long val = b[0];
            int cnt = 0;
            for (int i = 1; i < n; i++)
            {
                val += *it;
                if (abs(val - b[i])>=2)
                {
                    cnt = -1;
                    break;
                }
                else
                    cnt += (int)abs(val - (long long)b[i]);
            }
            if (cnt != -1 && cnt < ans)
                ans = cnt;
        }
        for (it = d.begin(); it != d.end(); it++)
        {
            long long val = b[0]-1;
            int cnt = 1;
            for (int i = 1; i < n; i++)
            {
                val += *it;
                if (abs(val - b[i])>=2)
                {
                    cnt = -1;
                    break;
                }
                else
                    cnt += (int)abs(val - (long long)b[i]);
            }
            if (cnt != -1 && cnt < ans)
                ans = cnt;
        }
        for (it = d.begin(); it != d.end(); it++)
        {
            long long val = b[0]+1;
            int cnt = 1;
            for (int i = 1; i < n; i++)
            {
                val += *it;
                if (abs(val - b[i])>=2)
                {
                    cnt = -1;
                    break;
                }
                else
                    cnt += (int)abs(val - (long long)b[i]);
            }
            if (cnt != -1 && cnt < ans)
                ans = cnt;
        }
        if (ans == 100001)
            cout << "-1";
        else
            cout << ans;
    }
    return 0;
}
