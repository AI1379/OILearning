#include<bits/stdc++.h>
using namespace std;
int Map[505][505];
bool f[505][505];
int h,w,m,ans,xl,yl;
void dfs(int x,int y){
	if(Map[x][y]-m<=Map[x+1][y]&&Map[x][y]+m>=Map[x+1][y]&&f[x+1][y]==false&&x+1<h){
		f[x+1][y]=true;
		dfs(x+1,y);
	}
	if(Map[x][y]-m<=Map[x-1][y]&&Map[x][y]+m>=Map[x-1][y]&&f[x-1][y]==false&&x-1>=0){
		f[x-1][y]=true;
		dfs(x-1,y);
	}
	if(Map[x][y]-m<=Map[x][y+1]&&Map[x][y]+m>=Map[x][y+1]&&f[x][y+1]==false&&y+1<w){
		f[x][y+1]=true;
		dfs(x,y+1);
	}
	if(Map[x][y]-m<=Map[x][y-1]&&Map[x][y]+m>=Map[x][y-1]&&f[x][y-1]==false&&y-1>=0){
		f[x][y-1]=true;
		dfs(x,y-1);
	}
}
bool s(){
	for(int i=xl;i<h;i++){
		for(int j=0;j<w;j++){
			if(f[i][j]==false){
				xl=i;
				yl=j;
				return false;
			}
		}
	}
	return true;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&h,&w,&m);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			scanf("%d",&Map[i][j]);
			f[i][j]=false;
		}
	}
	while(s()==false){
		f[xl][yl]=true;
		dfs(xl,yl);
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
