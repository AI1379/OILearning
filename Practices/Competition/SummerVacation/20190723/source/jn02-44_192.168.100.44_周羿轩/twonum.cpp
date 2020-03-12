#include<bits/stdc++.h>
#define l long long
using namespace std;
l n,m,h1,h2,a1,a2,x1,y_1,x2,y2,t;
int main(){
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	cin>>n;
	while(n--){
		t=0;
		cin>>m>>h1>>a1>>x1>>y_1>>h2>>a2>>x2>>y2;
		while(++t){
			if(t>m){
				cout<<-1<<endl;
				break;
			}
			h1=((x1%m)*(h1%m)+y_1%m)%m;
			h2=((x2%m)*(h2%m)+y2%m)%m;
			if(h1==a1&&h2==a2){
				cout<<t<<endl;
				break;
			}
		}
	}
	return 0;
} 
