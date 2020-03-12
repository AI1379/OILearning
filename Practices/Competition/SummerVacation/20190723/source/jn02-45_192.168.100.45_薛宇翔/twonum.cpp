#include<bits/stdc++.h>
using namespace std;
int T,a[6],aa[6],h[6],hh[6],x[6],xx[6],y[6],yy[6],m[6],ans[6],zz;
int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	cin>>T;
	for (int i=1;i<=T;i++)
	{
		cin>>m[i];
		cin>>h[i]>>a[i];
		cin>>x[i]>>y[i];
		cin>>hh[i]>>aa[i];
		cin>>xx[i]>>yy[i];
	}
	for (int i=1;i<=T;i++)
	{
		int s=h[i];
		int t=hh[i];
		while(h[i]!=a[i]&&hh[i]!=aa[i])
		{
			h[i]=(x[i]*h[i]+y[i])%m[i];
			hh[i]=(xx[i]*hh[i]+yy[i])%m[i];
			if (h[i]==s||hh[i]==t)
			{
				zz=1;
				cout<<"-1"<<endl;
				break;
			}
			ans[i]++;
		}
		if (zz!=1) cout<<ans[i]<<endl;
	}
}
