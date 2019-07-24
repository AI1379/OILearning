#include<bits/stdc++.h>
using namespace std;
long long t,l,r,k,ans,x,p,power[100];
int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	scanf("%lld",&t);
	power[0]=1;
	for(int i=1;i<=70;i++)
	power[i]=power[i-1]*2ULL;
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
		if(l>r)
		swap(l,r);
		ans=0;
		k=ceil(log2(r+1));
		for(long long i=ceil(log2(l+1));i<=k;i++)
		{
			x=power[i]-1;
			p=ceil(log2(power[i]-1-l));
			for(long long j=0;j<i-1&&j<=p;j++)
			{
				if(x-power[j]>=l&&x-power[j]<=r)
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
