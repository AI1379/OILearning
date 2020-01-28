#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	int a[202][202],n,minx=999,miny=999,maxx=-999,maxy=-999,y,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		a[y+100][x+100]=100;
		if(x+100>maxx)maxx=x+100;
		if(x+100<minx)minx=x+100;
		if(y+100>maxy)maxy=y+100;
		if(y+100<miny)miny=y+100;
	}
	maxx=max(maxx,100);
	maxy=max(maxy,100);
	minx=min(minx,100);
	miny=min(miny,100);
	for(int i=maxy;i>=miny;i--){
		for(int j=minx;j<=maxx;j++){
			if(a[i][j]==100)cout<<"*";
			else if(i==100&&j==100)cout<<"+";
			else if(i==100)cout<<"-";
			else if(j==100)cout<<"|";
			else cout<<".";
		}
		cout<<endl;
	}
	return 0;
}
