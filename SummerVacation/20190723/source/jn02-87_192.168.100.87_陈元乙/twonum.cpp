#include<bits/stdc++.h>
using namespace std;
long long m,h1,h2,a1,a2,X1,X2,Y1,Y2,ans,n;
map<unsigned long long,bool> M;
bool f;
int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	scanf("%lld",&n);
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&m,&h1,&a1,&X1,&Y1,&h2,&a2,&X2,&Y2);
		M.clear();
		ans=0;
		f=true;
		M[h1*1000001+h2]=true;
		while (h1!=a1 || h2!=a2)
		{
			h1=(X1*h1+Y1)%m;	
			h2=(X2*h2+Y2)%m;
			unsigned long long tmp=h1*1000001+h2;
			if (M[tmp])
			{
				printf("-1\n");
				f=false;
				break;
			}
			else
				M[tmp]=true;
			++ans;
		}
		if (f)
		{
			printf("%lld\n",ans);
		}
	}
	return 0;
}
