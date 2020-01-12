#include<bits/stdc++.h>
using namespace std;

long long l,r;
int t,ll;
long long p[65];
long long lov[2000];

int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	scanf("%d",&t);
	p[0]=1;
	for(int i=1;i<=60;i++)
		p[i]=p[i-1]*2;
	for(int i=1;i<=60;i++)
	{
		for(int j=i-2;j>=0;j--)
		{
			lov[++ll]=(long long)(p[i]-p[j]-1);
		} 
	}
	//for(int i=1;i<=ll;i++)
	//	cout<<lov[i]<<endl;
	int ans=0;
	while(t--)
	{
		ans=0;
		scanf("%lld%lld",&l,&r);
		for(int i=1;i<=ll;i++)
		{
			if(r<lov[i])
				break;
			if(l<=lov[i]&&r>=lov[i])
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

