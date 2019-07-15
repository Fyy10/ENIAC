#include<bits/stdc++.h>
using namespace std;

bool mat[10000][10000];

int main()
{
    int n,i;
    int x1,x2,y1,y2;
    while(scanf("%d",&n)==1)
    {
        if(n==0)
            break;
        memset(mat,0,sizeof(mat));
        int ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            for(int j=x1;j<x2;j++)
            {
                for(int k=y1;k<y2;k++)
                {
                    if(!mat[j][k])
                    {
                        mat[j][k]=1;
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
