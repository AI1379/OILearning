#include<bits/stdc++.h>
using namespace std;
const int MOD=100000007;
int ans,i,k,t,maxdep;
int solve(int m,int dep,int begin,int tmp){
	int j;
	if(tmp==m&&dep>=maxdep){
		ans=(ans+1)%MOD;
		return 0;
	}
	if(m<0||dep>maxdep)
		return 0;
	for(j=begin;j>=0;j--){
		if(dep<=maxdep)
			solve(m,dep+1,j,tmp+j);
	}
}
int main(){
	int m,n;
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	cin>>t;
	for(k=0;k<t;k++){
		ans=0;
		cin>>m>>n;
		maxdep=n;
		solve(m,1,m,0);
		cout<<ans<<endl;
	}
	return 0;
}
