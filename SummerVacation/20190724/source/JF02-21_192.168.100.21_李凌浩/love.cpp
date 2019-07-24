#include<bits/stdc++.h>
using namespace std;
long long y,p1,p2,t,l,r,ans,a1,a2,x;
bool p;
long long poww(int a, int b) {
	long long ans = 1, base = a;
	while (b != 0) {
		if (b & 1 != 0)
		ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>l>>r;
		if(log2(l)==(long long)log2(l)) p1=log2(l)+1;
		else p1=log2(l-(l&-l))+1;
		if(log2(r)==(long long)log2(r)) p2=log2(r)+1;
		else p2=log2(r-(r&-r))+1;
		//cout<<p1<<" "<<p2<<endl;
		ans=0,p=false;
		for(int i=p1;i<=p2;i++){//01ÊýÄ¿
		    x=poww(2,i)-1;
			for(int j=0;j<i-1;j++){
				y=poww(2,j);
		    	if(x-y>=l&&x-y<=r&&x-y!=1) ans++;
			}
		}
		cout<<ans<<endl;
	}
}
/*
l=5,r=10,p1=3,p2=4,p1_t=7
*/
