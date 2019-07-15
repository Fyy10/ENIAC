#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 201

struct node
{
    int left,right;
    int cover;
    double cnt;
    double lf,rf;
}tree[MAXN<<2];

struct line
{
    double lf,rf,y;
    int sign;       //down:1 up:-1
}scanl[MAXN];

double i2d[MAXN];

bool cmp(line a,line b)
{
    return a.y < b.y;
}

void build(int i,int left,int right)
{
    tree[i].left=left;
    tree[i].right=right;
    tree[i].lf=i2d[left];
    tree[i].rf=i2d[right];
    tree[i].cover=tree[i].cnt=0;
    if (left+1 == right) return;
    int mid = (left+right)>>1;
    build(i<<1,left,mid);
    build(i<<1|1,mid,right);
}

void cal(int i)
{
    if (tree[i].cover>0)
    {
        tree[i].cnt=tree[i].rf-tree[i].lf;
        return;
    }
    if (tree[i].right-tree[i].left==1) tree[i].cnt=0;
    else tree[i].cnt=tree[i<<1].cnt+tree[i<<1|1].cnt;
}

void update(int i,line l)
{
    if (tree[i].lf>=l.lf&&tree[i].rf<=l.rf)
    {
        tree[i].cover+=l.sign;
        cal(i);
        return;
    }
    if (tree[i].lf>=l.rf||tree[i].rf<=l.lf) return;
    update(i<<1,l);
    update(i<<1|1,l);
    cal(i);
}

int main()
{
    int n, i, t=0;
    double x1, y1, x2, y2;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        t++;
        for(i=0;i<n;i++)
        {
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            scanl[i<<1].lf=x1;
            scanl[i<<1].rf=x2;
            scanl[i<<1].y=y1;
            scanl[i<<1].sign=1;
            scanl[i<<1|1].lf=x1;
            scanl[i<<1|1].rf=x2;
            scanl[i<<1|1].y=y2;
            scanl[i<<1|1].sign=-1;
            i2d[i<<1]=x1;
            i2d[i<<1|1]=x2;
        }
        sort(i2d,i2d+2*n);
        sort(scanl,scanl+2*n,cmp);
        build(1,0,2*n-1);
        update(1,scanl[0]);
        double ans=0.0;
        for (i=1;i<2*n;++i)
        {
            ans+=(scanl[i].y-scanl[i-1].y)*tree[1].cnt;
            update(1,scanl[i]);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",t,ans);
    }
    return 0;
}
