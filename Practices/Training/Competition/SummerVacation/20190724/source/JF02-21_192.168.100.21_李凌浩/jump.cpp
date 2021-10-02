#include<bits/stdc++.h>
using namespace std;
const int dx[4]= {1,0,0,-1},dy[4]= {0,1,-1,0};
int ans,h,w,m,m_[501][501],h_[501][3],x,y,t,w_;
bool vis[501][501];
void doit(int p,int q) {
	t=0,w_=1;
	ans++,vis[p][q]=true,h_[1][1]=p,h_[1][2]=q;
	do {
		t++;
		for(int i=0; i<=3; i++) {
			x=h_[t][1]+dx[i],y=h_[t][2]+dy[i];
			if(x>=1&&x<=h&&y>=1&&y<=w&&abs(m_[x][y]-m_[h_[t][1]][h_[t][2]])<=m&&!vis[x][y]) {
				w_++;
				h_[w_][0]=x;
				h_[w_][1]=y;
				vis[x][y]=true;
			}
		}
	} while(t<w_);
}
int main() {
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>h>>w>>m;
	for(int i=1; i<=h; i++)
		for(int j=1; j<=w; j++)
			cin>>m_[i][j];
	for(int i=1; i<=h; i++)
		for(int j=1; j<=w; j++)
			if(!vis[i][j]) doit(i,j);
	cout<<ans/2;
}
