//Q1:jump.Coded dy Yjq.
#include<bits/stdc++.h>
using namespace std;
int h,w,m,ans;
int jm[502][502];
bool bm[502][502];
void dfs(int x,int y){
	if(bm[x][y]){
		return;
	}
	bm[x][y]=true;
	if(x!=1){
		if(abs(jm[x-1][y]-jm[x][y])<=m){
			dfs(x-1,y);
		}
	}
	if(y!=1){
		if(abs(jm[x][y-1]-jm[x][y])<=m){
			dfs(x,y-1);
		}
	}
	if(x!=h){
		if(abs(jm[x+1][y]-jm[x][y])<=m){
			dfs(x+1,y);
		}
	}
	if(y!=w){
		if(abs(jm[x][y+1]-jm[x][y])<=m){
			dfs(x,y+1);
		}
	}
	return;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout); 
	cin>>h>>w>>m;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>jm[i][j];
		}
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(!bm[i][j]){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
