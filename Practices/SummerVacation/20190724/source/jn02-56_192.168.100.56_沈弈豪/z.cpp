#include<bits/stdc++.h>
using namespace std;
long long n,m,p,k,s,ans=999999999;
int f[20001][20001],t[20001],u[20001],v[20001],x[20001],y[20001],z[20001];
int main()
{
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	cin>>n>>m>>p>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>t[i]>>u[i]>>v[i];
		s+=v[i]*u[i];
	}
	for(int i=1;i<=m;++i)
	{
		cin>>x[i]>>y[i]>>z[i];
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=v[i];++j)
		{
			for(long long k=u[i];k<=s;++k)
			{
//				if(f[i][k]==0)f[i][k]=f[i][k-1];
				if(k>=u[i])
				f[i][k]=max(f[i][k-u[i]]+t[i],f[i][k-1]);
					cout<<k<<" ";
				if(f[i][k]>p)
				{
					ans=min(ans,k);
				break;
				}
			}
			cout<<endl;
		}
	}
	cout<<ans;
}
