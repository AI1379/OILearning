#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	int t,a,b,c,ans=0;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b>>c;
		ans=0;
		while(c>0)
		{
			a--;
			b--;
			c--;
			ans++;
		}
		ans=ans+(a+b)/3;
		cout<<ans<<endl;
	}
	return 0;
}
