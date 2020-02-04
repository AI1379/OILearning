#include<bits/stdc++.h>
using namespace std;
bool B[1000][1000];
int A[1000][1000],h,w,m,ans;
void dfs(int x,int y)
{
	if(B[x][y]==1||x<=0||y<=0||x>h||y>w)
	{
		return;
	}
	B[x][y]=1;
	if(abs(A[x][y]-A[x][y-1])<=m)
	{
		dfs(x,y-1);
	}
	if(abs(A[x][y]-A[x-1][y])<=m)
	{
		dfs(x-1,y);
	}
	if(abs(A[x][y]-A[x][y+1])<=m)
	{
		dfs(x,y+1);
	}
	if(abs(A[x][y]-A[x+1][y])<=m)
	{
		dfs(x+1,y);
	}
	
}
int main()
{
	cin>>h>>w>>m;
	for(int i=1;i<=h;++i)
	{
		for(int j=1;j<=w;++j)
		{
			cin>>A[i][j];
		}
	}
	for(int i=1;i<=h;++i)
	{
		for(int j=1;j<=w;++j)
		{
			if(B[i][j]==0)
			{
				ans++;
				dfs(i,j);
			}
		}
	}
	cout<<ans;
}
