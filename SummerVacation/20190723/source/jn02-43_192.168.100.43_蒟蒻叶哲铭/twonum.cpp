#include<bits/stdc++.h>
using namespace std;
int t,m,x,xx,y,yy,w,ww,h,hh,pd,pdd,pddd;
long long ans;
bool b[1000001],bb[1000001];
int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		memset(b,false,sizeof(b));
		memset(bb,false,sizeof(bb));
		pd=0;pdd=0;ans=0;pddd=0;
		scanf("%d%d%d%d%d%d%d%d%d",&m,&h,&w,&x,&y,&hh,&ww,&xx,&yy);
		while(h!=w||hh!=ww)
		{
		    b[h]=true;bb[hh]=true;
			h=(h*x+y)%m;
			hh=(hh*xx+yy)%m;
			ans++;
			if(h==w)pd=1;
			if(hh==ww)pdd=1;
			if((b[h]==true&&bb[hh]==true&&(pd!=1||pdd!=1))||ans>10000000){pddd=1;printf("-1\n");break;}
		}
		if(pddd!=1)printf("%lld\n",ans);
	}
	return 0;
}
