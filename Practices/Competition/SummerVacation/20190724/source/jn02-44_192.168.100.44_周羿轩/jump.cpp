#include<bits/stdc++.h>
#define null 300
using namespace std;
int h,w,m,s,a[510][510],dxy[4][2]=
{
	0,1,
	0,-1,
	1,0,
	-1,0
};
void dfs(int x,int y,int z){
	a[x][y]=null;
	for(int i=0;i<4;i++){
		x+=dxy[i][0],y+=dxy[i][1];
		if(a[x][y]!=null&&a[x][y]<=z+m&&a[x][y]>=z-m) dfs(x,y,a[x][y]);
		x-=dxy[i][0],y-=dxy[i][1];
	}
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>h>>w>>m;
	for(int i=0;i<510;i++) for(int j=0;j<510;j++) a[i][j]=null;
	for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) cin>>a[i][j];
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(a[i][j]!=null){
				s++;
				dfs(i,j,a[i][j]);
				/*for(int ii=1;ii<=h;ii++){
					for(int jj=1;jj<=w;jj++){
						cout<<a[ii][jj]<<' ';
					}
					cout<<endl;
				}*/
			}
		}
	}
	cout<<s;
	return 0;
}
