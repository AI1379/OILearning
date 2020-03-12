#include<bits/stdc++.h>
using namespace std;
int t,n,m,ans;
void dfs(int sc,int sy,int sl)
{   

    if(sl==n)
	{
		if(sy==0)
		{ans++;
		}
		return;
	}
	if(sc>sy)return;
	
	for(int i=sc;i<=sy;i++)
	{
		dfs(i,sy-i,sl+1);
	}
	dfs(sc+1,sy,sl);
}
int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>m>>n;
		ans=0;
		dfs(0,m,0);
		cout<<ans<<endl;
	}
}
