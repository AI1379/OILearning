#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
long long ans=0;
int t;
int m,n;
void dfs(int k,int l,int h){
	if(k>=n+1){
		if(h==m){
		  ans=(ans+1)%MOD;	
		}
		return;
	}
	if(k<=n&&h==m)return;
	int i;
	for(i=l;i<=m;i++){
		if(h+i<=m){
			dfs(k+1,i,h+i);
		}
	}
}
int main(){
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	scanf("%d",&t);
	while(t>0){
		ans=0;
		scanf("%d%d",&m,&n);
		dfs(1,0,0);
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
