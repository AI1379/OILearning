#include<bits/stdc++.h>
using namespace std;
unsigned long long W,H,w,h,ans=0;
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>W>>H;
	cin>>w>>h;
	if(W<H)
	    swap(W,H);
	if(w<h)
	    swap(w,h);
	if(W<w || H<h)
	{
	    cout<<-1;
		return 0;
	}
	while(W>w)
	{
		ans++;
		if(W%2)
		    W=W/2+1;
		else
		    W/=2;
	}
	while(H>h)
	{
		ans++;
		if(H%2)
		    H=H/2+1;
		else
		    H/=2;
	}
	cout<<ans;
	return 0;
}
