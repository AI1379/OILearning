#include<bits/stdc++.h>
using namespace std;
long long w,h,ww,hh,ans;
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	scanf("%lld%lld%lld%lld",&w,&h,&ww,&hh);
	if(w>h)swap(w,h);
	if(ww>hh)swap(ww,hh);
	if(w<ww||h<hh){printf("-1");return 0;}
	while(ww<w)
	{
		ww*=2;ans++;
	}
	while(hh<h)
	{
		hh*=2;ans++;
	}
	printf("%d",ans);
	return 0;
}
