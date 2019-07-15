#include<bits/stdc++.h>
#define random(a,b) ((a)+rand()%((b)-(a)+1))
using namespace std;

stringstream ss;

int main(int argc, char *argv[])
{
    int seed = time(NULL);
    if(argc > 1)
    {
        ss.clear();
        ss<<argv[1];
        ss>>seed;
    }
    srand(seed);
    int t=10;
    for(int i=0;i<t;i++)
    {
        int n=random(1,10);
        cout << n << endl;
        int j=0;
        while(j<n)
        {
            int x1=random(0,100);
            int y1=random(0,100);
            int x2=random(0,100);
            int y2=random(0,100);
            if(x1<x2&&y1<y2)
            {
                cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
                j++;
            }
        }
    }
    cout << "0" << endl;
    return 0;
}
