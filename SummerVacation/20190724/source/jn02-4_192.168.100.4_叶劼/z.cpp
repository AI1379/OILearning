#include<bits/stdc++.h>
using namespace std;
int n,m,p,k,t[201],u[201],v[201],x[201],y[201],z[201],ans1,ans2,c=1e9;
void dfs1(int x,int s,int q)
{
	if(x==n+1)
	{
		if(s-p<c)
		{
			ans1=q;
			c=s-p;
		}
		return;
	}
	for(int i=1;i<=v[x] && i*t[x]+s<p+c;i++)
	    dfs1(x+1,s+i*t[x],q+u[x]*i);
}
int main()
{
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	cin>>n>>m>>p>>k;
	for(int i=1;i<=n;i++)
	    cin>>t[i]>>u[i]>>v[i];
	for(int i=1;i<=m;i++)
	    cin>>x[i]>>y[i]>>z[i];
	dfs1(1,0,0);
	cout<<ans1<<endl;
	c=1e9;
	for(int i=1;i<=m;i++)
	    if((ans1*1.0*x[i]+49*1.0/99)<z[i])
		    if(ans2>(ans1*1.0*x[i]+49*1.0/99)*y[i])
		        ans2=(ans1*1.0*x[i]+49*1.0/99)*y[i];
		else
		    if(ans2>z[i]*y[i])
		        ans2=z[i]+y[i];
	cout<<ans2;
	return 0;
}
