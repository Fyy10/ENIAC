#include<bits/stdc++.h>
#define eps 2e-60
#define LL long long
using namespace std;

struct point
{
    double x;
    double y;
};

struct intPoint
{
    int x;
    int y;
};

double cross(point A, point B)      //A cross B
{
    return A.x*B.y - B.x*A.y;
}

double dot(point A, point B)        //A dot B
{
    return A.x*B.x + A.y*B.y;
}

double L(point A)                   //length of A
{
    return sqrt(dot(A,A));
}

LL LS(intPoint A)                   //L squared
{
    return (LL)A.x*(LL)A.x + (LL)A.y*(LL)A.y;
}

double angle(point A, point B)      //angle of A, B
{
    return acos(dot(A,B)/(L(A)*L(B)));
}

intPoint ipoints[50000];

int main()
{
    int n, t;
    cin >> t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&ipoints[i].x,&ipoints[i].y);
        }
        if(n == 4)              //Problem here
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
