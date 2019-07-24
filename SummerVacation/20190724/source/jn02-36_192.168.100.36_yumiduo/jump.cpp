#include<bits/stdc++.h>
using namespace std;
int n,m,k,ma[501][501],vis[501][501],cnt;
void search(int x,int y,int color)
{
	vis[x][y]=color;
	if(x>1)
	{
		if(abs(ma[x-1][y]-ma[x][y])<=k&&vis[x-1][y]==0)
		{
			vis[x-1][y]=color;
			search(x-1,y,color);
		}
	}
	if(y>1)
	{
		if(abs(ma[x][y-1]-ma[x][y])<=k&&vis[x][y-1]==0)
		{
			vis[x][y-1]=color;
			search(x,y-1,color);
		}
	}
	if(x<n)
	{
		if(abs(ma[x+1][y]-ma[x][y])<=k&&vis[x+1][y]==0)
		{
			vis[x+1][y]=color;
			search(x+1,y,color);
		}
	}
	if(y<m)
	{
		if(abs(ma[x][y+1]-ma[x][y])<=k&&vis[x][y+1]==0)
		{
			vis[x][y+1]=color;
			search(x,y+1,color);
		}
	}
	return;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		scanf("%d",&ma[i][j]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j]==0)
			search(i,j,++cnt);
		}
	}
	printf("%d",cnt);
	return 0;
}
