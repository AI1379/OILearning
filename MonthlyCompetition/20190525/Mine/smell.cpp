#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int main(){
	long long ans=0,a[1000],b[1000],i,j,n;
	freopen("smell.in","r",stdin);
	freopen("smell.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		a[i]%=MOD;
	}
	for(i=0;i<n;i++){
		cin>>b[i];
		b[i]%=MOD;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			//ans=(ans+(a[i]*a[i])%MOD+(2*a[i]*b[i])%MOD+(b[i]*b[i])%MOD)%MOD;
			ans=(ans+((a[i]+b[j])%MOD)*((a[i]+b[j])%MOD)%MOD)%MOD;
		}
	}
	cout<<ans;
	return 0;
}
