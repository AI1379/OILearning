#include<bits/stdc++.h>
using namespace std;
unsigned long long W,H,w,h,ans,ww,hh,anss;
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>W>>H>>w>>h;
	if (W<w || H<h)
	{
		ans=2e9;
	}
	else
	{
		ww=w;
		hh=h;
		while (ww<W)
			ww*=2,ans++;
		while (hh<H)
			hh*=2,ans++;
	}
	swap(w,h);
	if (W<w || H<h)
	{
		anss=2e9;
	}
	else
	{
		ww=w;
		hh=h;
		while (ww<W)
			ww*=2,anss++;
		while (hh<H)
			hh*=2,anss++;
	}
	ans=min(ans,anss);
	if (ans==2e9)
		cout<<-1;
	else
		cout<<ans;
	return 0;
}
