#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-20;

struct point
{
    double x;
    double y;
    point operator - (const point& a)
    {
        point tmp;
        tmp.x = x - a.x;
        tmp.y = y - a.y;
        return tmp;
    }
    point operator + (const point& a)
    {
        point tmp;
        tmp.x = x + a.x;
        tmp.y = y + a.y;
        return tmp;
    }
    point operator = (const point& a)
    {
        x = a.x;
        y = a.y;
        return (point){x,y};
    }
    double operator * (const point& a)  //dot product
    {
        return x*a.x+y*a.y;
    }
    double operator ^ (const point& a)  //cross product
    {
        return x*a.y-y*a.x;
    }
};

double L(point A)                   //length of A
{
    return sqrt(A*A);
}

bool equ(double a, double b)
{
    return fabs(a-b) < eps;
}

bool pout(point a, point C, double R)     //out circle
{
    return L(a-C) > R;
}

point center3(point A, point B, point C)
{
    double a1 = B.x-A.x, b1 = B.y-A.y, c1 = (a1*a1+b1*b1)/2;
    double a2 = C.x-A.x, b2 = C.y-A.y, c2 = (a2*a2+b2*b2)/2;
    double d = a1*b2 - a2*b1;
    point tmp;
    tmp.x = A.x + (c1*b2 - c2*b1)/d;
    tmp.y = A.y + (a1*c2 - a2*c1)/d;
    return tmp;
}

point center2(point A, point B)
{
    point tmp;
    tmp.x = 0.5*(A.x+B.x);
    tmp.y = 0.5*(A.y+B.y);
    return tmp;
}

point ps[100000];

int main()
{
    int n;
    point C;
    double R;
    while(scanf("%d",&n)==1)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%lf %lf",&ps[i].x,&ps[i].y);
        }
        random_shuffle(ps,ps+n);
        C = ps[0];
        R = 0.0;
        for(int i=1;i<n;i++)
        {
            if(pout(ps[i],C,R))
            {
                C = ps[i];
                R = 0.0;
                for(int j=0;j<i;j++)
                {
                    if(pout(ps[j],C,R))
                    {
                        C = center2(ps[i],ps[j]);
                        R = 0.5 * L(ps[i]-ps[j]);
                        for(int k=0;k<j;k++)
                        {
                            if(pout(ps[k],C,R))
                            {
                                C = center3(ps[i],ps[j],ps[k]);
                                R = L(ps[k]-C);
                            }
                        }
                    }
                }
            }
        }
        printf("%.3lf\n%.3lf %.3lf\n",R,C.x,C.y);
    }
    return 0;
}
