#include<bits/stdc++.h>
using namespace std;
int t;
long long l,r,ans=0,ll,rr,p;
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		p=1;
		cin>>l>>r;
		int t1=log(l)/log(2)+1,t2=log(r)/log(2)+1;
		ll=pow(2,t1),rr=pow(2,t2);
		for(int i=t1;i<t2;i++){
			ans+=i;
		}
		ll--;
		while(ll-p>=l){
			p*=2;
			ans++;
		}
		p=1;
		rr--;
		while(rr-p>r){
			p*=2;
			ans--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
