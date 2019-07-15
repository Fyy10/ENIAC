#include<bits/stdc++.h>
using namespace std;

bool judge(int a, int b, int c)
{
    return (a < b+c) && (b < a+c) && (c < a+b);
}

int main()
{
    int n;
    bool flag = true;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (!judge(a, b, c))
        {
            flag = false;
        }
    }
    if (flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
