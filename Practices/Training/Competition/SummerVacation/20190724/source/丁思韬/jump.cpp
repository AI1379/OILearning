//Coded by dst
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int n,m,d,h[505][505],ans,w[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool vis[505][505];
void dfs(int x,int y){
	int i,nx,ny;
	vis[x][y]=1;
	for(i=0;i<4;i++){
		nx=x+w[i][0];
		ny=y+w[i][1];
		if(!vis[nx][ny]&&abs(h[nx][ny]-h[x][y])<=d)
			dfs(nx,ny);
	}
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int i,j;
	memset(h,127,sizeof(h));
	scanf("%d%d%d",&n,&m,&d);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&h[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(!vis[i][j]){
				dfs(i,j);
				ans++;
			}
	printf("%d",ans);
	return 0;
} 
