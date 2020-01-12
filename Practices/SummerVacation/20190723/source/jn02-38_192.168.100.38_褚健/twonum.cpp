#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

long long T,h1,h2,a1,a2,x1,x2,y1,y2,m;

int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		int f=0;
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&m,&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
		for(int i=1;i<=1000000;i++)
		{
			h1=((h1*x1)%m+y1)%m;
			h2=((h2*x2)%m+y2)%m;
			if(a1==h1&&a2==h2)
			{
				printf("%d\n",i);
				f=1;
				break;
			}
		}
		if(!f) printf("-1\n");
	}
}
