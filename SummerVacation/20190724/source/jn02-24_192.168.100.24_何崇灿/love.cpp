#include<bits/stdc++.h>
using namespace std;
int t,o,y,ans[10002];
long long l,r,n;
int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin >> t;
	for(int e=1;e<=t;e++)
	{
		cin >> l>> r;
		if(l>r)
		{
			o=l;
			l=r;
			r=o;
		}
		for(long long i=l;i<=r;i++)
		{
			y=0;
		    n=i;
			while(n>0)
	        {
	        	if(n%2==0)y++;
		        n/=2;
	        }
	        if(y==1)ans[e]++;
		}
	}
	for(int i=1;i<=t;i++) cout<<ans[i]<<endl;
	return 0;
}
