#include<bits/stdc++.h>
using namespace std;
int n,nn,m,w[301],v[301],t;
long long ans[301],M=100000007;
int main()
{
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	scanf("%d",&t);
	for(int ii=1;ii<=t;++ii)
	{
    	scanf("%d%d",&m,&nn);
    	n=m;
    	if(nn>m)nn=m;
    	memset(ans,0,sizeof(ans));
    	for(int i=1;i<=n;++i)w[i]=i;
	    ans[0]=1;
    	for(int i=1;i<=nn;++i)
    	{
	    	for(int j=w[i];j<=m;++j)ans[j]=(ans[j]+ans[j-w[i]])%M;
	    }
        printf("%lld\n",ans[m]%M);
    }
	return 0;
}
