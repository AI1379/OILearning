#include<bits/stdc++.h>
using namespace std;int a[501][501];bool pan[501][501];int h,w,m;
void dfs(int x,int y)
{
	pan[x][y]=0;
	if(pan[x+1][y]&&abs(a[x+1][y]-a[x][y])<=m) dfs(x+1,y);
	if(pan[x-1][y]&&abs(a[x-1][y]-a[x][y])<=m) dfs(x-1,y);
	if(pan[x][y+1]&&abs(a[x][y+1]-a[x][y])<=m) dfs(x,y+1);
	if(pan[x][y-1]&&abs(a[x][y-1]-a[x][y])<=m) dfs(x,y-1);
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
     int count=0;
	cin>>h>>w>>m;
	for(int i=1;i<=h;i++)
	for(int j=1;j<=w;j++)
	{
		cin>>a[j][i];
	}
	for(int i=1;i<=h;i++)
	for(int j=1;j<=w;j++)
	{
		pan[j][i]=1;
	}
	for(int i=1;i<=h;i++)
	for(int k=1;k<=w;k++)
	{
		if(pan[k][i]) 
		{
			dfs(k,i);
			count++;
		}
	}
	cout<<count<<endl;
}
