#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n, ans = 0, cnt = 0;
    char s[101];
    cin >> n;
    scanf("%s", s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'x')
            cnt++;
        else
            cnt = 0;
        if (cnt >= 3)
            ans++;
    }
    cout << ans;
    return 0;
}
