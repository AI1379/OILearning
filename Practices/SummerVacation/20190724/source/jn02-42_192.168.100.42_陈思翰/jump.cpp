#include<bits/stdc++.h>
using namespace std;
int n,w,m,a[502][502],ans=1e9;
bool vis[502][502];
void dfs(int x,int y,int rest,int step){
	if(vis[x][y]=0){
		rest--;
		vis[x][y]=1;
	}
	if(step>=ans)return;
	if(rest==0&&step<ans){
		ans=step;
		return;
	}
	if((a[x][y]-m)<=a[x-1][y]&&(a[x][y]+m)>=a[x-1][y]&&x>1){
		    dfs(x-1,y,rest,step);
	    	vis[x-1][y]=0;
	    }  
	else{
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=w;j++){
				if(vis[i][j])dfs(i,j,rest,step+1);
		}
	} 
	} 
	if((a[x][y]-m)<=a[x+1][y]&&(a[x][y]+m)>=a[x+1][y]&&x<=w-1){
		    dfs(x+1,y,rest,step);
	    	vis[x+1][y]=0;
	    }  
	    else{
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=w;j++){
				if(vis[i][j])dfs(i,j,rest,step+1);
		}
	} 
	} 
	if((a[x][y]-m)<=a[x][y+1]&&(a[x][y]+m)>=a[x][y+1]&&y<=n-1){
		    dfs(x,y+1,rest,step);
	    	vis[x][y+1]=0;
	    }
	    else{
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=w;j++){
				if(vis[i][j])dfs(i,j,rest,step+1);
		}
	} 
	} 
	if((a[x][y]-m)<=a[x][y-1]&&(a[x][y]+m)>=a[x][y-1]&&y>1){
		    dfs(x,y-1,rest,step);
	    	vis[x][y-1]=0;
	    }
	    else{
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=w;j++){
				if(vis[i][j])dfs(i,j,rest,step+1);
		}
	} 
	} 
}
int main(){
	cin>>n>>w>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=w;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=w;j++){
				memset(vis,0,sizeof(vis));
				dfs(i,j,n*w,1);
		}
	} 
	return 0;
}
