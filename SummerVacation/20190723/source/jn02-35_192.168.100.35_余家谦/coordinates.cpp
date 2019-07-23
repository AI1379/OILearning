#include<bits/stdc++.h>
using namespace std;
int cmap[202][202];
int n,x,y,minx=210,maxx=-1,miny=210,maxy=-1;
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		cmap[x+101][y+101]=-1;
		maxx=max(x+101,maxx);
		minx=min(x+101,minx);
		maxx=max(y+101,maxy);
		miny=min(y+101,miny);
	}
	for(int i=maxy;i>=min(101,miny);i--){
		for(int j=min(101,minx);j<=maxx;j++){
			if(cmap[i][j]==-1){
				cout<<'*';
			}else{
				if(i==101&&j==101){
					cout<<'+';
				}else{
					if(j==101){
						cout<<'|';
					}else{
						if(i==101){
							cout<<'-';
						}else{
							cout<<'.';
						}
					}
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
