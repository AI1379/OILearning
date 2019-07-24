#include <bits/stdc++.h>
using namespace std;
int h,w,m;
int front,rear;
int he[501][501];
bool bl[501][501],vi[501][501];
int x,y,z,a,b,c,d,ans=0;
void yy(int q,int e)
{     int a,b;
      bl[q][e]=true;
      vi[q][e]=true;
	  a=he[q][e]-h;
	  b=he[q][e]+h;
	  if (a<=he[q-1][e]&&he[q-1][e]<=b&&q>1&&e<=m&&q<=w&&vi[q-1][e]==false) yy(q-1,e);
	  if (a<=he[q+1][e]&&he[q+1][e]<=b&&e<=m&&q<w&&vi[q+1][e]==false) yy(q+1,e);
	  if (a<=he[q][e+1]&&he[q][e+1]<=b&&e<m&&q<=w&&vi[q][e+1]==false) yy(q,e+1);
	  if (a<=he[q][e-1]&&he[q][e-1]<=b&&e>1&&e<=m&&q<=w&&vi[q][e-1]==false) yy(q,e-1);
}
int main()
{   
    freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>w>>m>>h;
	for(int i=1;i<=w;i++)
	for(int j=1;j<=m;j++)
	cin>>he[i][j]; 
	for(int i=1;i<=w;i++)
	for(int j=1;j<=m;j++)
	{ 
	if(bl[i][j]==false)
	{
	yy(i,j);
	ans++;
	memset(vi,0,sizeof(vi)); 
	}
	}
	cout<<ans;
}

