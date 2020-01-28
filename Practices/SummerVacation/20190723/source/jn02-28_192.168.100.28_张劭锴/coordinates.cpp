#include<bits/stdc++.h>
using namespace std;
char c[310][310];
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	int n,x,y,maxx=0,minx=1e8,maxy=0,miny=1e8;
	cin>>n;
	memset(c,'.',sizeof(c));
	for(int j=0;j<310;j++) c[100][j]='|',c[j][100]='-'; 
	c[100][100]='+';
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		c[x+100][y+100]='*';
		maxx=max(maxx,x+100);
		minx=min(minx,x+100);
		maxy=max(maxy,y+100);
		miny=min(miny,y+100);
	}
	minx=min(minx,100);
	miny=min(miny,100);
	for(int a=maxy;a>=miny;a--){
		for(int b=minx;b<=maxx;b++)
			cout<<c[b][a];
		cout<<endl;
	}
	return 0;
}
