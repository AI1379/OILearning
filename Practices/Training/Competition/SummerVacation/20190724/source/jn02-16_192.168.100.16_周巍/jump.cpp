#include<bits/stdc++.h>
using namespace std;
int w,h,m,a[501][501],vis[501][501],ans=1e9,p=1e9;;
void dfs(int i,int j,int sum,int k){
//	cout<<i<<" "<<j<<endl;

	if(sum==(w*h)) {
		p=min(p,k);
		return;
	};
	if(!vis[i][j])
	{	
		vis[i][j]=1;
	if(a[i+1][j]<=a[i][j]+m&&a[i+1][j]>=a[i][j]-m&&!vis[i+1][j]&&i+1>=1&&i+1<=h&&j>=1&&j<=m) 
	{
		dfs(i+1,j,sum+1,k);
		vis[i+1][j]=0;
	}
//	else
//		if(a[i+1][j]<=a[i][j]+m&&a[i+1][j]>=a[i][j]-m&&vis[i+1][j]) 
//	{
//		dfs(i+1,j,sum,k);
//		vis[i+1][j]=0;
//	}
	else
	if(!vis[i+1][j]&&i+1>=1&&i+1<=h&&j>=1&&j<=w)
	{
		dfs(i+1,j,sum+1,k+1);
		vis[i+1][j]=0;
	}
//	else if(vis[i+1][j]){
//		dfs(i+1,j,sum,k+1);
//		vis[i+1][j]=0;
//	}
		if(a[i][j+1]<=a[i][j]+m&&a[i][j+1]>=a[i][j]-m&&!vis[i][j+1]&&i>=1&&i<=h&&j+1>=1&&j+1<=w) 
	{
		dfs(i,j+1,sum+1,k);
		vis[i][j+1]=0;
	}
//	else
//	if(a[i][j+1]<=a[i][j]+m&&a[i][j+1]>=a[i][j]-m&&vis[i][j+1]) 
//	{
//		dfs(i,j+1,sum,k);
//		vis[i][j+1]=0;
//	}
	else
	if(!vis[i][j+1]&&i>=1&&i<=h&&j+1>=1&&j+1<=w)
	{
		dfs(i,j+1,sum+1,k+1);
		vis[i][j+1]=0;
	}
//	else
//	if(vis[i][j+1])
//	{
//		dfs(i,j+1,sum,k+1);
//		vis[i][j+1]=0;
//	}
		if(a[i][j-1]<=a[i][j]+m&&a[i][j-1]>=a[i][j]-m&&!vis[i][j-1]&&i>=1&&i<=h&&j-1>=1&&j-1<=w) 
	{
		dfs(i,j-1,sum+1,k);
		vis[i][j-1]=0;
	}
//	else
//	if(a[i][j-1]<=a[i][j]+m&&a[i][j-1]>=a[i][j]-m&&vis[i][j-1]) 
//	{
//		dfs(i,j-1,sum,k);
//		vis[i][j-1]=0;
//	}
	else if(!vis[i][j-1]&&i>=1&&i<=h&&j-1>=1&&j-1<=w){
		dfs(i,j-1,sum+1,k+1);
		vis[i][j-1]=0;
	}
//	else
//	if(vis[i][j-1]){
//		dfs(i,j-1,sum,k+1);
//		vis[i][j-1]=0;
//	}
		if(a[i-1][j]<=a[i][j]+m&&a[i-1][j]>=a[i][j]-m&&!vis[i-1][j]&&i-1>=1&&i-1<=h&&j>=1&&j<=w) 
	{
		dfs(i-1,j,sum+1,k);
		vis[i-1][j]=0;
	}
//	else if(a[i-1][j]<=a[i][j]+m&&a[i-1][j]>=a[i][j]-m&&vis[i-1][j]) 
//	{
//		dfs(i-1,j,sum,k);
//		vis[i-1][j]=0;
	else if(!vis[i-1][j]&&i-1>=1&&i-1<=h&&j>=1&&j<=w){
		dfs(i-1,j,sum+1,k+1);
		vis[i-1][j]=0;
	}
//	else
//	if(vis[i-1][j]){
//		dfs(i-1,j,sum,k+1);
//		vis[i-1][j]=0;
//	}
	}
	else return;
	
	
	
	
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>h>>w>>m;
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			for(int ii=1;ii<=h;ii++)
			for(int jj=1;jj<=w;jj++)
			vis[ii][jj]=0;
			p=1e9; 
			dfs(i,j,1,1);
			ans=min(ans,p);
		}
	}
  
	cout<<ans<<endl;
	return 0;
}
