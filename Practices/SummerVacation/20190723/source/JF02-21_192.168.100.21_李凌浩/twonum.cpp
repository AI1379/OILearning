#include<bits/stdc++.h>
using namespace std;
bool x=false;
int top,a[1000001],b[1000001],T,mod,h1,h2,xa,ya,xb,yb,a1,a2;
int main() {
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	cin>>T;
	while(cin>>mod>>h1>>a1>>xa>>ya>>h2>>a2>>xb>>yb) {
		a[0]=h1,b[0]=h2,top=0,x=false;
		while(1) {
			if(a[top]==a1&&b[top]==a2) break;
			if(top>1000000||a[top]==a[top-1]||b[top]==b[top-1]) {
				cout<<"-1"<<endl;
				x=true;
				break;
			}
			top++;
			a[top]=(xa*a[top-1]%mod+ya)%mod;
			b[top]=(xb*b[top-1]%mod+yb)%mod;
		}
		if(!x)cout<<top<<endl;
	}
}
