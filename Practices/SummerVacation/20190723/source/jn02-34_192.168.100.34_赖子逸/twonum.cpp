#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	int a;
	cin>>a;
	for(int i=1;i<=a;i++){
		int h1,h2,w1,w2,x1,x2,y1,y2,a1,a2,ans=-1,m;
		cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
		for(int j=1;j<=50;j++){
			w1=(x1*w1+y1)%m;
			w2=(x2*w2+y2)%m;
			if(w1==a1&&w2==a2){
				ans=j;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
