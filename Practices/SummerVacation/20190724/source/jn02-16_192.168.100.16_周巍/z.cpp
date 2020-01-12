#include<bits/stdc++.h>
using namespace std;
double t[500001],u[500001],v[500001],x[500001],y[500001],z[500001],l=-100,n,m,p,k;
int main()
{
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	cin>>n>>m>>p>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i]>>u[i]>>v[i];
		k=t[i]/u[i];
		l=max(k,l);
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
	}
	cout<<p/l<<endl;
	cout<<"FAIL"<<endl;
	return 0;
	
}
