#include<bits/stdc++.h>
using namespace std;
int ans;
void dfs(int ret,int step,int e){
	if(ret==0&&step==0){
		ans++;
		return;
	}
	else if(step==0)return;
	for(int i=e;i<=ret;i++){
		dfs(ret-i,step-1,i);
	}
}
int main(){
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	int m,n,t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>m>>n;	
		ans=0;
		dfs(m,n,0);
		cout<<ans%100000007<<endl;
	}
	return 0;
}
