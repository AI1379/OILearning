#include<bits/stdc++.h>
using namespace std;
inline void fop(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	return;
}
int H,W,M;
short h[500][500],jp[500][500];
int t=1;
inline void dfs(int i,int j,short num){
	//cout<<"dfs:"<<i<<" "<<j<<" "<<num<<endl;
	if(i+1<=H&&jp[i+1][j]==0&&abs(h[i+1][j]-h[i][j])<=M){
		jp[i+1][j]=num;
		dfs(i+1,j,num);
	}
	if(i-1>=1&&jp[i-1][j]==0&&abs(h[i-1][j]-h[i][j])<=M){
		jp[i-1][j]=num;
		dfs(i-1,j,num);
	}
	if(j+1<=W&&jp[i][j+1]==0&&abs(h[i][j+1]-h[i][j])<=M){
		jp[i][j+1]=num;
		dfs(i,j+1,num);
	}
	if(j-1>=1&&jp[i][j-1]==0&&abs(h[i][j-1]-h[i][j])<=M){
		jp[i][j-1]=num;
		dfs(i,j-1,num);
	}
	return;
}
int main(){
	fop();
	cin>>H>>W>>M;
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			cin>>h[i][j];
		}
	}
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			if(jp[i][j]==0){
				dfs(i,j,t);
				t+=1;
			}
		}
	}
	cout<<t-1;
	return 0;
}
