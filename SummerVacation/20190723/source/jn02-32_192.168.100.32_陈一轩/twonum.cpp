#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	int t,tot=0,h1,h2,a1,a2,x1,x2,y1,y2,w1,w2,m;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>m;
		cin>>h1>>a1>>x1>>y1;
		cin>>h2>>a2>>x2>>y2;
		w1=h1;w2=h2;
		while(w1!=a1&&w2!=a2)	
		{
			w1=(x1*w1+y1)%m;
			w2=(x2*w2+y2)%m;
			tot++;
		}
		cout<<tot;
	}
	return 0;
}
