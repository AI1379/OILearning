#include<bits/stdc++.h>
using namespace std;
int m,h1,h2,t,ya,yb,x1,x2,a,b,a1,a2;
int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>m;
		cin>>h1>>a1;
		cin>>x1>>ya;
		cin>>h2>>a2;
		cin>>x2>>yb;
		a=h1,b=h2;
			int ti=0;
		while(1)
		{
			if(h1==a1&&h2==a2)
			{
				cout<<ti<<endl;
				break;
			}
			h1=(h1*x1%m+ya)%m;
			h2=(h2*x2%m+yb)%m;
//			cout<<h1<<" "<<h2<<"    "; 
			ti++;
			if(h1==a&&h2==b)
			{
				cout<<"-1\n";
				break;
			}
		}
	}
	return 0;
}
