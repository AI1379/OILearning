#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const long long mod=100000007;
long long T,n,m,ans;

long long f(long long a,long long b,long long c)
{
    long long g=0,i;
    if(b==1) g=1;
    else
		for(i=c;i<=a/b;i++)
        	g+=f(a-i,b-1,i),g%=mod;
    return g%mod;
}

int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		ans=0;
		scanf("%lld%lld",&m,&n);
		for(int i=1;i<=n;i++) ans+=f(m,i,1),ans%=mod;
		printf("%lld\n",ans);
	}
}
