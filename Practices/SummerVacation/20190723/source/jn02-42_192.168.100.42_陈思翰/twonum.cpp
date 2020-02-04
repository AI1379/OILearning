#include<bits/stdc++.h>
using namespace std;
    long long a1,a2,x1,x2,yy1,y2,h1,h2,t,m,ti,w1,w2;
	bool a[1001][1001],p=0;
int main(){
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>m;
		cin>>h1>>a1;
		cin>>x1>>yy1;
		cin>>h2>>a2;
		cin>>x2>>y2;
	    p=0;
		ti=0;
		memset(a,0,sizeof(a));
		while(a[h1][h2]!=1){
			a[h1][h2]=1;
			w1=(x1*h1+yy1)%m;
			w2=(x2*h2+y2)%m;
			if(w1==h1&&w1!=a1||w2==h2&&w2!=a2)break;
			else {
				h1=w1;
				h2=w2;
			}
			if(a[a1][a2]==1){
				p=1;
				break;
			}
			else ti++;
		}
		if(p==1)cout<<ti<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
