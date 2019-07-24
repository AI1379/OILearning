#include<bits/stdc++.h>
using namespace std;

double n,x,y,xx,yy,k,b,ans;

int main()
{
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>xx>>yy;
	}
	k=(yy-y)/(xx-x);
	b=y-k*x;
	ans=b*b/-4;
	cout<<ans;
	return 0;
}
