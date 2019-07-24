#include<bits/stdc++.h>
using namespace std;
int h,w,m,ans=1,f[510][510];
bool a[510][510],ff;
void dfs(int x,int y){
	ff=false;
	a[x][y]=false;
	if(a[x-1][y]&&abs(f[x-1][y]-f[x][y])<=m) ff=true,dfs(x-1,y);
	if(a[x][y+1]&&abs(f[x][y+1]-f[x][y])<=m) ff=true,dfs(x,y+1);
	if(a[x+1][y]&&abs(f[x+1][y]-f[x][y])<=m) ff=true,dfs(x+1,y);
	if(a[x][y-1]&&abs(f[x][y-1]-f[x][y])<=m) ff=true,dfs(x,y-1);
	if(ff==false){
		if(a[x-1][y]) ff=true,dfs(x-1,y);
		if(a[x][y+1]) ff=true,dfs(x,y+1);
		if(a[x+1][y]) ff=true,dfs(x+1,y);
		if(a[x][y-1]) ff=true,dfs(x,y-1);
		ans++;
	}
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);	
	cin>>h>>w>>m;
	for(int u=1;u<=h;u++)
		for(int l=1;l<=w;l++)
			a[u][l]=true;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			cin>>f[i][j];
	dfs(1,1);
	cout<<ans;
	return 0;
}
