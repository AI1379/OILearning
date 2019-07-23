#include<bits/stdc++.h>
using namespace std;
long long W,H,w,h,ans,anss,minn=0x7f7f7f7f;
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	scanf("%lld%lld%lld%lld",&W,&H,&w,&h);
	if(w>h)
	swap(w,h);
	if(W>H)
	swap(W,H);
	if(W<w||H<h)
	{
		printf("-1");
		return 0;
	}
	minn=min(ceil(log2((double)W/w))+ceil(log2((double)H/h)),ceil(log2((double)W/h))+ceil(log2((double)H/w)));
	printf("%lld",minn);
	return 0;
}

/*
100 50 25 12.5 6.25 3.675 1.8375 0.9
15 20
3 5

17 20
3 4

*/
