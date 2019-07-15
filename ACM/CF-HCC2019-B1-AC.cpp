#include<bits/stdc++.h>
#define LL long long
using namespace std;

struct base
{
    int def;
    int gol;
}bases[100000];

bool cmp(struct base a, struct base b)
{
    return a.def < b.def;
}

int att[100000];
LL presum[100000];

int main()
{
    int s, b;
    cin >> s >> b;
    for (int i = 0; i < s; i++)
    {
        scanf("%d",&att[i]);
    }
    for (int i = 0; i < b; i++)
    {
        scanf("%d %d", &bases[i].def, &bases[i].gol);
    }
    sort(bases, bases + b, cmp);
    presum[0] = (LL)bases[0].gol;
    for (int i = 1; i < b; i++)
    {
        presum[i] = presum[i-1] + (LL)bases[i].gol;
    }
    for(int i = 0; i < s; i++)
    {
        base tmp = {att[i], 0};
        int idx = upper_bound(bases, bases + b, tmp, cmp) - bases - 1;
        printf("%lld ", presum[idx]);
    }
    return 0;
}
