#include<bits/stdc++.h>
using namespace std;
long long t,m,h1,h2,a1,a2,x1,x2,yy1,y2;
bool flag;
int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		flag=true;
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&m,&h1,&a1,&x1,&yy1,&h2,&a2,&x2,&y2);
		for(int i=1;i<=15000000;i++)
		{
			h1=(h1*x1+yy1)%m;
			h2=(h2*x2+y2)%m;
			if(h1==a1&&h2==a2)
			{
				printf("%d\n",i);
				flag=false;
				break;
			}
		}
		if(flag==true)
		printf("-1\n");
	}
	return 0;
}
