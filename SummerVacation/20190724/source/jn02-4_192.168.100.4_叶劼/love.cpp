#include<bits/stdc++.h>
using namespace std;
long long t,l,r,ans;
int ejz(int x)
{
	int s=0;
	while(x>0)
	{
		if(x%2==0)
		    s++;
		x/=2;
	}
	return s;
}
int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>l>>r;
		ans=0;
		for(int j=l;j<=r;j++)
		    if(ejz(j)==1)
		        ans++;
		cout<<ans<<endl;
	}
	return 0;
}
