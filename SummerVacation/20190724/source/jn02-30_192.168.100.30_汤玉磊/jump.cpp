#include<bits/stdc++.h>
using namespace std;
int H,W,M;
int dmap[501][501];
bool vst[501][501];
int dx[5] = {0,1,-1,0,0};
int dy[5] = {0,0,0,-1,1};
int read()
{
	char ch=getchar(); int x=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-48; ch=getchar();}
	return x;
}
void dfs(int x,int y){
	int yx,yy;
	vst[x][y] = 1;
				yx = x;yy = y;
		for(int i = 1;i <= 4;i++){
			x = yx + dx[i];y = yy + dy[i];
			if(x >= 1 && y >= 1 && dmap[yx][yy] + M >= dmap[x][y] && dmap[yx][yy] - M <= dmap[x][y] && x <= H && y <= W){
				if(!vst[x][y]){
					dfs(x,y);
				}
			}
		}
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin >> H >> W >> M;
	for(int i = 1;i <= H;i++){
		for(int j = 1;j <= W;j++){
			dmap[i][j] = read();
		}
	}
	memset(vst,0,sizeof(vst));
	int ans = 0;
	for(int i = 1;i <= H;i++){
		for(int j = 1;j <= W;j++){
			if(!vst[i][j]){
				ans++;
				dfs(i,j);
			}
			
		}
	}
	cout << ans;
}
