#include<bits/stdc++.h>
using namespace std;
struct jd
{
  int x,y;
};
jd q[250001];
int ma[501][501],n,m,mm,i,j,k,x,y,h,t,sum,now,ans;
bool b[501][501];
void push(int x,int y)
{
    if(ma[x][y]>now+mm||ma[x][y]<now-mm)return;
    if(b[x][y]==true)return;
    now=ma[x][y];
    if(b[x][y]==false)sum++;
    b[x][y]=1;
    q[++t].x=x; q[t].y=y;
    if(sum==n*m){printf("%d",ans);exit(0);}
}
void bfs()
{
	do
    {
        h++;
        x=q[h].x; y=q[h].y;
        if (x!=n)  push(x+1,y);
        if (y!=m)  push(x,y+1);    
        if (x!=1)  push(x-1,y);  
        if (y!=1)  push(x,y-1); 
    }
    while (h<t);
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    scanf("%d%d%d",&n,&m,&mm);
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)scanf("%d",&ma[i][j]);
    for(int i=1;i<=n;++i)
    {
   	    for(int j=1;j<=m;++j)if(b[i][j]==false)
   	    { 
   		    ans++;now=ma[i][j];h=t=0;push(i,j);bfs();
	    }
    }
    return 0;
}
