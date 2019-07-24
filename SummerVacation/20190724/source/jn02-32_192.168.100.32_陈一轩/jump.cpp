#include<bits/stdc++.h>
using namespace std;
int h,w,m,tot,a[510][510];
bool v[510][510];
void dfs(int x,int y)
{
	v[x][y]=false;
	int h1=a[x][y]-m;
	int h2=a[x][y]+m;
	if(v[x+1][y]&&a[x+1][y]>=h1&&a[x+1][y]<=h2)dfs(x+1,y);
	if(v[x][y+1]&&a[x][y+1]>=h1&&a[x][y+1]<=h2)dfs(x,y+1);
	if(v[x-1][y]&&a[x-1][y]>=h1&&a[x-1][y]<=h2)dfs(x-1,y);
	if(v[x][y-1]&&a[x][y-1]>=h1&&a[x][y-1]<=h2)dfs(x,y-1);
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
	  v[i][j]=true;
	for(int i=1;i<=h;i++)
	 for(int j=1;j<=w;j++)
	 	if(v[i][j])
		 {
		 	dfs(i,j);
	 		tot++;
		 }
	 cout<<tot<<endl;
	 return 0;
}
