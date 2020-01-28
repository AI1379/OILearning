#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,m,ans;
void dfs(int dep,int res,int l)
{
	if(dep>n) return ;
	if(dep==n&&res>=l) 
	{
		ans++;
		ans%=100000007;
		return;
	}
	for(register int i=0;res-i-l>=l*(n-dep);i++)
	{
//		cout<<dep<<' '<<l+i<<endl;
		dfs(dep+1,res-i-l,l+i);
	}
}
int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		cin>>m>>n;
		ans=0;
		dfs(1,m,0);
		cout<<ans<<endl;
	}
}
/*
0 1 6
0 2 5
0 3 4
1 2 5
1 3 4
*/
