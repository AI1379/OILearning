#include<bits/stdc++.h>
using namespace std;
int h,w,m,ma[510][510],ans; bool vis[510][510];
int d1[4]={0,0,1,-1},d2[4]={1,-1,0,0};
void dfs(int x,int y){
	for(int i=0; i<4; i++){
		int x1=x+d1[i],yy=y+d2[i];
		if((!vis[x1][yy])&&(abs(ma[x][y]-ma[x1][yy])<=m)&&(x1>0&&yy>0&&yy<=w&&x1<=h)){
			vis[x1][yy]=1; dfs(x1,yy);
		}
	}
	return;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&h,&w,&m);
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			scanf("%d",&ma[i][j]);
		}
	}
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			if(!vis[i][j]){
				dfs(i,j); ans++;
			} 
		}
	}
	cout<<ans;
	return 0;
}
