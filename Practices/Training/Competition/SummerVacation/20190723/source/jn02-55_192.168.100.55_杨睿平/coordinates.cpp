#include <bits/stdc++.h>
using namespace std;
int ans[205][205],n,mx=100,my=100,nx=100,ny=100;
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	scanf("%d",&n);
	ans[100][100]=10;
	int i,j,x,y;
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		mx=max(mx,x+100);
		my=max(my,y+100);
		nx=min(nx,x+100);
		ny=min(ny,y+100);
		ans[y+100][x+100]=1;
	}
	//cout<<mx<<' '<<my<<' '<<nx<<' '<<ny<<' '<<endl;
	for(i=1;i<=200;i++){
		if(i!=100&&ans[i][100]==0)ans[i][100]=3;
	}
	for(i=1;i<=200;i++){
		if(i!=100&&ans[100][i]==0)ans[100][i]=2;
	}
	for(i=my;i>=ny;i--){
		for(j=nx;j<=mx;j++){
			if(ans[i][j]==10)cout<<'+';
			if(ans[i][j]==1)cout<<'*';
			if(ans[i][j]==2)cout<<'-';
			if(ans[i][j]==3)cout<<'|';
			if(ans[i][j]==0)cout<<'.';
		}
		cout<<endl;
	} 
	return 0;
}
