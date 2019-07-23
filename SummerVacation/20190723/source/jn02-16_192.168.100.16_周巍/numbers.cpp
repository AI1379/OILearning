#include<bits/stdc++.h>
using namespace std;
int n,m,ans,s[301],mod=100000007,t;
void  dfs(int x,int m){
	if(x>n) return;
	if(m==0)
	{
		if(x==n) ans++;
	} else for(int i=s[x-1];i<=m;i++){
		s[x]=i;
		dfs(x+1,m-i);
	}
}
int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=300;i++) s[i]=0;
		s[0]=0;
		dfs(1,m);
		ans%=mod;
		cout<<ans<<endl;
	}
	
	return 0;
}
