#include<bits/stdc++.h>
using namespace std;
long long a,b[5010];
long long f[5010];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	memset(f,0xf,sizeof(f));
	f[1]=0;
	scanf("%lld",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&b[i]);
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			if(j-i<=b[i]) f[j]=min(f[j],f[i]+1);
			else break;
		}
	}
	printf("%lld",f[a]);
	return 0;
}
