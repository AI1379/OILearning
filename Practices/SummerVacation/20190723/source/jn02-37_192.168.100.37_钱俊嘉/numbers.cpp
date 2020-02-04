#include<bits/stdc++.h>
using namespace std;
int T,m,n;
long long ans;
const int MOD=100000007;
void dfs(int dep,int sum,int minn){
	if(dep==n){
		if(sum==m) ans++;
	}
	else{
		if(dep<=n){
			for(int i=minn;i<=((m-sum)/(n-dep));i++){
				if(sum+i<=m) dfs(dep+1,sum+i,i);
			}
			
		}
		
	}
}
int main(){
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>m>>n;
		dfs(0,0,0);
		cout<<ans%MOD<<endl;
	}
	return 0;
}
