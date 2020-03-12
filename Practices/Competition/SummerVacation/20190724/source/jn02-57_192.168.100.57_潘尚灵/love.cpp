#include<bits/stdc++.h>
using namespace std;
long long t,l,r,ans,a,b,c,d,s;
int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin>>t;
	int i,j,k;
	for(i=1;i<=t;i++)
	{
		cin>>l>>r;
		a=l;
		c=d=1;
		b=s=0;
		while(a!=0)
		{
			a/=2;
			b++;
			c*=2;
		}
		a=r;
		while(a!=0)
		{
			a/=2;
			s++;
		}
		ans=0;
		for(j=b;j<=s+1;j++)
		{
			d=1;
			if((c-d-1)>=l&&(c-d-1)<=r)
				ans++;
			for(k=1;k<j-1;k++)
			{
				d*=2;
				if((c-d-1)>=l&&(c-d-1)<=r)
					ans++;
			}
			c*=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
