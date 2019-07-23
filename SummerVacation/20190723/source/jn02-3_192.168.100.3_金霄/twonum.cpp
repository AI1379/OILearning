#include<bits/stdc++.h>
using namespace std;

int T,m,a1,a2,h1,h2,x,xx,y,yy;
unsigned long long ans=0;

int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		ans=0;
		cin>>m>>h1>>a1>>x>>y>>h2>>a2>>xx>>yy;
		while(1)
		{	
			ans++;
			h1=(h1*x+y)%m;
			h2=(h2*xx+yy)%m;
			if(h1==a1&&h2==a2)
			{
				cout<<ans<<endl;
				break;
			}
			if(ans==500000)
			{
				cout<<-1<<endl;
				break;
			}
		}
		
	}
	return 0;
}
