#include<bits/stdc++.h>

using namespace std;
int h,w,m;
int a[400][400];
int b[400][400],ans;
void s(int x,int y)
{
    if(b[x][y]) return ;
    b[x][y]=1;
    // cout<<x<<y<<endl;
    if(x<1||x>w||y<1||y>h) return ;
    if(a[x+1][y]<=a[x][y]+m&&a[x+1][y]>=a[x][y]-m) s(x+1,y);
    if(a[x-1][y]<=a[x][y]+m&&a[x-1][y]>=a[x][y]-m) s(x-1,y);
    if(a[x][y+1]<=a[x][y]+m&&a[x][y+1]>=a[x][y]-m) s(x,y+1);
    if(a[x][y-1]<=a[x][y]+m&&a[x][y-1]>=a[x][y]-m) s(x,y-1);
}
int main()
{
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    cin>>h>>w>>m;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            cin>>a[i][j];
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        {
            if(!b[i][j])
            {
                s(i,j),ans++;
            }
        }
    cout<<ans;
}

