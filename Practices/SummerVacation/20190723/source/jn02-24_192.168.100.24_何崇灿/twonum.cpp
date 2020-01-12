#include<bits/stdc++.h>
using namespace std;
int cs,m,h1,h2,a1,a2,x1,x2;
int ans,k,l,z1,z2,t[101];
int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	cin>> cs;
	for(int e=1;e<=cs;e++)
	{
		cin>>m;
		cin>>h1>>a1;
		cin>>x1>>z1;
		cin>>h2>>a2;
		cin>>x2>>z2;
		k=h1,l=h2;
		ans=0;
		while(h1!=a1||h2!=a2)
		{
			h1=(h1*x1+z1)%m;
			h2=(h2*x2+z2)%m;
			ans++;
			if(h1==k||h2==l)
			{
				ans=-1;
			    break;
			}
		}
		t[e]=ans;
	}
	for(int i=1;i<=cs;i++) cout<<t[i]<<endl;
	return 0;
}
