#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

long long w,h,W,H,ans;

int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	scanf("%lld%lld%lld%lld",&W,&H,&w,&h);
	if(W<H) swap(W,H);
	if(w<h) swap(w,h);
	if(W<w||H<h)
	{
		printf("-1");
		return 0;
	}
	while(w<W)
	{
		w*=2;
		ans++;
	}
	while(h<H)
	{
		h*=2;
		ans++;
	}
	printf("%lld",ans);
}
