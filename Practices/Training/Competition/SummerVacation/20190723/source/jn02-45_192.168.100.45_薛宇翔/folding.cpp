#include<bits/stdc++.h>
using namespace std;
int W,H,w,h,sum1,sum2,sum3,sum4;
int main()
{	
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>W>>H>>w>>h;
	if (W<w&&H<w)
	{
		cout<<-1;
		return 0;
	}
	if (W<h&&H<h)
	{
		cout<<-1;
		return 0;
	}
	for (int i=1;i<=9999;i++)
	{
		W=W/2.0;
		sum1++;
		if (W<=w) break;
	}
	for (int i=1;i<=9999;i++)
	{
		H=h/2.0;
		sum2++;
		if (H<=h) break;
	}for (int i=1;i<=9999;i++)
	{
		W=W/2.0;
		sum1++;
		if (W<=h) break;
	}for (int i=1;i<=9999;i++)
	{
		H=H/2.0;
		sum2++;
		if (H<=w) break;
	}
	cout<<min(sum1,sum2);
	return 0;
}
