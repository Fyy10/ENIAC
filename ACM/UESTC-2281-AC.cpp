#include<bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
    int left, right;
    int cover;
    int l, r, cnt;
}tree[100000];

struct line
{
    int l, r, y;
    int flag;       //down:1 up:-1
}scanl[20001];

int i2i[20001];

bool cmp(line a, line b)
{
    return a.y < b.y;
}

void build(int x, int left, int right)
{
    tree[x].left = left;
    tree[x].right = right;
    tree[x].l = i2i[left];
    tree[x].r = i2i[right];
    tree[x].cover = tree[x].cnt = 0;
    if (left + 1 == right) return;
    int mid = (left+right)>>1;
    build(x<<1,left,mid);
    build(x<<1|1,mid,right);
}

void cal(int x)
{
    if (tree[x].cover > 0)
    {
        tree[x].cnt = tree[x].r-tree[x].l;
        return;
    }
    if (tree[x].right - tree[x].left == 1)
    {
        tree[x].cnt = 0;
    }
    else
    {
        tree[x].cnt = tree[x<<1].cnt + tree[x<<1|1].cnt;
    }
}

void update(int x, line a)
{
    if (tree[x].l >= a.l && tree[x].r <= a.r)
    {
        tree[x].cover += a.flag;
        cal(x);
        return;
    }
    if (tree[x].l >= a.r || tree[x].r <= a.l)
        return;
    update(x<<1,a);
    update(x<<1|1,a);
    cal(x);
}

signed main()
{
    int n, i;
    int x1, y1, x2, y2;
    while(scanf("%lld",&n)==1)
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
            scanl[i<<1].l = x1;
            scanl[i<<1].r = x2;
            scanl[i<<1].y = y1;
            scanl[i<<1].flag = 1;
            scanl[i<<1|1].l = x1;
            scanl[i<<1|1].r = x2;
            scanl[i<<1|1].y = y2;
            scanl[i<<1|1].flag = -1;
            i2i[i<<1] = x1;
            i2i[i<<1|1] = x2;
        }
        sort(i2i,i2i+2*n);
        sort(scanl,scanl+2*n,cmp);
        build(1,0,2*n-1);
        update(1,scanl[0]);
        int ans = 0;
        for (i=1;i<2*n;i++)
        {
            ans += (scanl[i].y - scanl[i-1].y) * tree[1].cnt;
            update(1,scanl[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
