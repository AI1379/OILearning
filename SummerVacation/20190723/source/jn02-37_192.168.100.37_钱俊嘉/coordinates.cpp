#include<bits/stdc++.h>
using namespace std;
bool mp[500][500];
int n,maxx=100,maxy=100,minx=100,miny=100;
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	memset(mp,0,sizeof(mp));
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		x+=100,y+=100;
		maxx=max(maxx,x);
		maxy=max(maxy,y);
		minx=min(minx,x);
		miny=min(miny,y);
		mp[x][y]=1;
	}
	for(int i=maxy;i>=miny;i--){
		for(int j=minx;j<=maxx;j++){
			if(mp[j][i]==1) cout<<"*";
			else{
				if(i==100&&j==100) cout<<"+";
				if(i==100&&j!=100) cout<<"-";
				if(i!=100&&j==100) cout<<"|";
				if(i!=100&&j!=100) cout<<".";
			}
		}
		cout<<endl;
	}
	return 0;
}
