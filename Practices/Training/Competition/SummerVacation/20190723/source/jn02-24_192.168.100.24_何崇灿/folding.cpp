#include<bits/stdc++.h>
using namespace std;
int W,H,w,h,o,ans=0;
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin >>W>>H>>w>>h;
	if(W<w&&H<w||W<h&&H<h)
	{
		cout<<"-1";
		return 0;
	}
	if(W<h)o=H,H=W,W=o;
	if(w<h)o=h,h=w,w=o;	
	while(W>2*w)
	{
		W/=2;
		ans++;
	}
	while(H>2*h)
	{
		H/=2;
		ans++;
	}
	if(W==w) ans--;
	if(H==h) ans--;
	cout<<ans+2;
	return 0;
}

