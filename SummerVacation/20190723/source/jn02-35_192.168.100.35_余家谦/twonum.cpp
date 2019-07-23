#include<bits/stdc++.h>
using namespace std;
int x1,y3,x2,y2,m,h1,h2,a1,a2,t,tt;
int tn(int x,int y){
	if(x==a1&&y==a2){
		return tt;
	}else{
		tt++;
		x=(x*x1+y3)%m;
		y=(y*x2+y2)%m;
		return tn(x,y);
	}
}
int main(){
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>m;
		cin>>h1>>a1;
		cin>>x1>>y3;
		cin>>h2>>a2;
		cin>>x2>>y2;
		if(y3==0||y2==0){
			cout<<-1<<endl;
		}else{
			tt=0;
			cout<<tn(h1,h2)<<endl;
		}
	}
	return 0;
}
