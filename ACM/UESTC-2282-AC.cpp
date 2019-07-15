#include<bits/stdc++.h>
#define eps 2e-60
using namespace std;

/*struct point
{
    double x;
    double y;
};*/

struct intPoint
{
    int x;
    int y;
    intPoint operator - (const intPoint& A)
    {
        intPoint tmp;
        tmp.x=x-A.x;
        tmp.y=y-A.y;
        return tmp;
    }
};

intPoint ipoints[50000];
int sides[50000];
int n, p;

/*double cross(point A, point B)      //A cross B
{
    return A.x*B.y - B.x*A.y;
}*/

int cross(intPoint A, intPoint B)      //A cross B
{
    return A.x*B.y - B.x*A.y;
}

/*double dot(point A, point B)        //A dot B
{
    return A.x*B.x + A.y*B.y;
}*/

int dot(intPoint A, intPoint B)        //A dot B
{
    return A.x*B.x + A.y*B.y;
}

/*double L(point A)                   //length of A
{
    return sqrt(dot(A,A));
}*/

int LS(intPoint A)                   //L squared
{
    return dot(A,A);
}

/*double angle(point A, point B)      //angle of A, B
{
    return acos(dot(A,B)/(L(A)*L(B)));
}*/

bool cmp(intPoint A, intPoint B)
{
    return A.x<B.x || (A.x==B.x && A.y<B.y);
}

bool equ(intPoint A, intPoint B)
{
    return A.x==B.x && A.y==B.y;
}

void generate()
{
    intPoint O;
    sort(ipoints,ipoints+n,cmp);
    O=ipoints[0];
    p=0;
    sides[p++]=0;
    sides[p++]=1;
    for(int i=2;i<n;i++)
    {
        while(p>1 && cross(ipoints[i]-ipoints[sides[p-1]],ipoints[sides[p-1]]-ipoints[sides[p-2]]) <= 0)
        {
            p--;
        }
        sides[p++]=i;
    }
    O=ipoints[n-1];
    for(int i=n-2;i>=0;i--)
    {
        while(cross(ipoints[i]-ipoints[sides[p-1]],ipoints[sides[p-1]]-ipoints[sides[p-2]]) <= 0)
        {
            if(sides[p-1]==n-1)
                break;
            p--;
        }
        sides[p++]=i;
    }
    if(equ(ipoints[0],ipoints[sides[p-1]]))
        p--;
}

int findmax()
{
    if(p == 2)
        return LS(ipoints[sides[1]]-ipoints[sides[0]]);
    int maxd=0;
    #define nxt(x) (x+1)%p
    intPoint O=ipoints[0];
    intPoint A=ipoints[sides[1]];
    int q=1;
    for(int i=0;i<p;i++)
    {
        while(cross(ipoints[sides[q]]-ipoints[sides[nxt(i)]],ipoints[sides[nxt(i)]]-ipoints[sides[i]])
        <
        cross(ipoints[sides[nxt(q)]]-ipoints[sides[nxt(i)]],ipoints[sides[nxt(i)]]-ipoints[sides[i]]))
        {
           q=nxt(q);
        }
        maxd=max(maxd,max(LS(ipoints[sides[q]]-ipoints[sides[i]]),LS(ipoints[sides[nxt(q)]]-ipoints[sides[nxt(i)]])));
    }
    return maxd;
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&ipoints[i].x,&ipoints[i].y);
    }
    if(n<=1)
    {
        cout << "0";
    }
    else
    {
        generate();
        cout << findmax() << endl;
    }
    /*for(int i=0;i<p;i++)
    {
        cout << ipoints[sides[i]].x << ' ' << ipoints[sides[i]].y << endl;
    }*/
    return 0;
}
