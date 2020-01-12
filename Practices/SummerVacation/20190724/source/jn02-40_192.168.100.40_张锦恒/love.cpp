#include <bits/stdc++.h>
using namespace std;

long long t,l,r;
unsigned long long p2[64],a[100001],tot;

int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	p2[0]=1;
	for(int i=1 ; i<=63 ; i++) p2[i]=p2[i-1]*2;
	for(int i=2 ; i<=63 ; i++)
		for(int j=1 ; j<=i-1 ; j++)
			a[++tot]=p2[i]-1-p2[j];
	cin>>t;
	while(t--)
	{
		long long ans=0;
		cin>>l>>r;
		if(l==1) l=2;
		for(int i=1 ; i<=tot ; i++)
			if(a[i]<=r&&a[i]>=l)
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}
