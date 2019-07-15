#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    set<string> s;
    while (cin >> n)
    {
        s.clear();
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            sort(str.begin(), str.end());
            string tmp;
            tmp.clear();
            char last = str[0];
            tmp = tmp + last;
            for (int j = 1; j < str.length(); j++)
            {
                if (str[j] == last)
                {
                    continue;
                }
                else
                {
                    last = str[j];
                    tmp = tmp + last;
                }
            }
            s.insert(tmp);
        }
        printf("%d\n", s.size());
    }
    return 0;
}
