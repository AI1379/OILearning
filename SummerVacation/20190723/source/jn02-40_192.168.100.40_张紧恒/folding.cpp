#include <bits/stdc++.h>
#define LoL long long
using namespace std;

void pow_2();
LoL trytry(LoL W,LoL H,LoL w,LoL h)
{
	int ans=0;
	if(w>W||h>H)
		return -1;
	while(0==0)
	{
		if(w>=W)
		{
			if(h>=H)
				return ans;
			else
				ans++,h*=2;
		}
		else
		{
			if(h>=H)
				ans++,w*=2;
			else
				ans+=2,w*=2,h*=2;
		}
	}
}

int main()
{
	LoL W,H,w,h,ans1,ans2;
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>W>>H>>w>>h;
	ans1=trytry(W,H,w,h);
	ans2=trytry(W,H,h,w);
	if(ans1==-1)
	{
		if(ans2==-1)
			cout<<-1;
		else
			cout<<ans2;
	}
	else
	{
		if(ans2==-1)
			cout<<ans1;
		else
			cout<<min(ans1,ans2);
	}
	return 0;
}
