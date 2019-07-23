#include<bits/stdc++.h>
using namespace std;
int n,m,t,ans;
void dfs(int x,int s,int p)
{
	if(x==n)
	{
	    if(s==m)
	    {
		    ans++;
		}
		return;
	}
	if(s>m)
	    return;
	for(int i=p;s+i<=m;i++)
	{
	    dfs(x+1,s+i,i);
	}
}
int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		ans=0;
		cin>>m>>n;
		dfs(0,0,0);
		if(i==1)
		    cout<<ans%100000007;
		else
		    cout<<endl<<ans%100000007;
	}
	return 0;
}
