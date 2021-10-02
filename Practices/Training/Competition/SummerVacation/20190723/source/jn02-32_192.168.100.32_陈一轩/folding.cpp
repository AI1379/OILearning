#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	int W,H,w,h,c1=0,c2=0,t1,t2,ans1,ans2;
	cin>>W>>H>>w>>h;
	if(max(w,h)>W&&max(w,h)>H)
	{
		cout<<-1<<endl;
		exit(0);
	}
	t1=W;
	while(t1>w)
	{
		t1/=2;c1++;
	}
	t2=H;
	while(t2>h)
	{
		t2/=2;c2++;
	}
	ans1=c1+c2;
	c1=0,c2=0;
	t1=W;
	while(t1>h)
	{
		t1/=2;c1++;
	}
	t2=H;
	while(t2>w)
	{
		t2/=2;c2++;
	}
	ans2=c1+c2;
	cout<<min(ans1,ans2);
	return 0;
}
