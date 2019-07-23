#include<bits/stdc++.h>
using namespace std;
int x1,x2,yy,y2,n; bool s[110][110][9];
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int a,b,c=0; scanf("%d%d",&a,&b);
		if(a>0&&b>0) c=1; if(a>0&&b<0) c=2;
		if(a<0&&b>0) c=3; if(a<0&&b<0) c=4;
		if(a==0){
			if(b>0) c=7; if(b<0) c=8;
		}
		if(b==0){
			if(a>0) c=5; if(a<0) c=6;
		}
		s[abs(a)][abs(b)][c]=1;
		x1=max(a,x1); x2=min(x2,a);
		yy=max(b,yy); y2=min(y2,b);
	}
	for(int i=yy; i>0; i--){
		for(int j=x2; j<=x1; j++){
			if(j>0){
				if(s[j][i][1]==1){cout<<"*"; continue;}
				cout<<".";
			}
			if(j==0){
				if(s[j][i][7]==1){cout<<"*"; continue;}
				cout<<"|";
			}
			if(j<0){
				if(s[-j][i][3]==1){cout<<"*"; continue;}
				cout<<".";
			}
		}
		cout<<endl;
	}
	for(int j=x2; j<=x1; j++){
		int c=5; if(j<0) c=6;
		if(s[abs(j)][0][c]==1){cout<<"*"; continue;}
		if(j==0) cout<<"+";
		else cout<<"-";
	}
	cout<<endl;
	for(int i=-1; i>=y2; i--){
		for(int j=x2; j<=x1; j++){
			if(j>0){
				if(s[j][-i][2]==1){cout<<"*"; continue;}
				cout<<".";
			}
			if(j==0){
				if(s[j][-i][8]==1){cout<<"*"; continue;}
				cout<<"|";
			}
			if(j<0){
				if(s[-j][-i][4]==1){cout<<"*"; continue;}
				cout<<".";
			}
		}
		cout<<endl;
	}
	return 0;
}
