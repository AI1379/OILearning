#include<bits/stdc++.h>
using namespace std;
const int MAXL=505;
const int MAXN=200005;
const int dx[5]={0,0,1,0,-1};
const int dy[5]={0,1,0,-1,0};
int H,W,M,nx,ny,a[MAXL][MAXL];
int tot,fst[MAXN],nxt[MAXN],to[MAXN],ans;
bool vis[MAXN];
void add(int x,int y){
	to[++tot]=y,nxt[tot]=fst[x],fst[x]=tot;
}
void dfs(int x){
	vis[x]=true;
	for (int i=fst[x];i;i=nxt[i])
		if (!vis[to[i]]) dfs(to[i]);
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&H,&W,&M);
	for (int i=1;i<=H;i++)
		for (int j=1;j<=W;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=H;i++)
		for (int j=1;j<=W;j++)
			for (int k=1;k<=4;k++){
				nx=i+dx[k],ny=j+dy[k];
				if ((nx>=1)&&(nx<=H)&&(ny>=1)&&(ny<=W))
					if (abs(a[nx][ny]-a[i][j])<=M)
						add((i-1)*W+j,(nx-1)*W+ny);
			}
	for (int i=1;i<=H*W;i++)
		if (!vis[i]) dfs(i),ans++;
	printf("%d",ans);
	return 0;
}
