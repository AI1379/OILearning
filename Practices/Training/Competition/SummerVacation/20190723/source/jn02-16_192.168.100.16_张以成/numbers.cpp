#include<bits/stdc++.h>
using namespace std;
int n,m,t,ans;
inline void dfs(int last,int sum,int more){
	//cout<<last<<" "<<sum<<" "<<more<<endl;
	if(sum==n&&more==0){
		ans+=1;
		ans%=100000007;
		return;
	}
	if(more<last||sum>n){
		return;
	}
	for(int i=last;i<=more;i++){
		dfs(i,sum+1,more-i);
	}
}
inline void mn(){
	cin>>n>>m;
	ans=0;
	dfs(0,0,m);
	cout<<ans<<endl;
}
int main(){
	freopen("numbers.in","r"stdin);
	freopen("numbers.out","w"stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		mn();
	}
}
