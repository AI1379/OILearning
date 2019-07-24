#include<bits/stdc++.h>
using namespace std;
int h,w,m,a[501][501],ans=0;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
bool vis[505][505];
const int INF=-999999999;
void dfs(int x,int y){
	for(int i=1;i<=4;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(a[x][y]<=(a[tx][ty]+m)&&a[x][y]>=(a[tx][ty]-m)&&!vis[tx][ty]){
			vis[tx][ty]=1;
			dfs(tx,ty);
		}
	}
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>h>>w>>m;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=500;i++){
		for(int j=0;j<=500;j++) a[i][j]=INF/3;
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(!vis[i][j]){
				ans++;
				dfs(i,j);
			}
		}
	}
	cout<<ans;
	return 0;
}
