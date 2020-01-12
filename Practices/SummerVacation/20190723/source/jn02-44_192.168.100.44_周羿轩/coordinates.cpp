#include<bits/stdc++.h>
#define MAX 110
using namespace std;
int n,x[300],y[300],bx,by,sx,sy;
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		bx=max(bx,x[i]);
		by=max(by,y[i]);
		sx=min(sx,x[i]);
		sy=min(sy,y[i]);
	}
	for(int i=by;i>=sy;i--){
		for(int j=sx;j<=bx;j++){
			if(i==0&&j==0){
				cout<<'+';
				continue;
			}
			for(int k=1;k<=n;k++){
				if(i==y[k]&&j==x[k]){
					cout<<'*';
					goto a;
				}
			}
			if(i==0) cout<<'-';
			else if(j==0) cout<<'|';
			else cout<<'.';
			a:;
		}
		cout<<endl;
	}
	return 0;
} 
