#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	long long W,H,w,h;
	bool fw=0,fh=0,fW=0,fH=0;
	long long ans=0;
	cin>>W>>H>>w>>h;
	if((W<w && H<w) || (W<h && H<h))
	{
		cout<<"-1";
		return 0;
	}
	while(1)
	{
		if(fW==1 && fH==1 && fw==1 && fh==1) break;
		if(W==w)
		{
			fW=1;
			fw=1;
		}
		else if(W==h)
		{
			fW=1;
			fh=1;
		}
		else if(W<=2*w && fw==0 && fW==0)
		{
			W=w;
			fw=1;
			fW=1;
			ans++;
		}
		else if(W<=2*h && fh==0 && fW==0)
		{
			W=h;
			fW=1;
			fh=1;
			ans++;
		}
		else
		{
			W/=2;
			ans++;
		}
		
		
		if(H==w)
		{
			fH=1;
			fw=1;
		}
		else if(H==h)
		{
			fH=1;
			fh=1;
		}
		else if(H<=2*w && fw==0 && fH==0)
		{
			H=w;
			fw=1;
			fH=1;
			ans++;
		}
		else if(H<=2*h && fh==0 && fH==0)
		{
			H=h;
			fH=1;
			fh=1;
			ans++;
		}
		else
		{
			H/=2;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
