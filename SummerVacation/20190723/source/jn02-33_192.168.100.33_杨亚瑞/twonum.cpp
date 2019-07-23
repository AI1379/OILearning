#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	int n;int count=0;
	cin>>n;
	int m,h1,a1,x1,y1,h2,a2,x2,y2;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
		count=0;
		int w1=h1;
		int w2=h2;
		while(w1!=a1&&w2!=a2)
		{
			w1=(x1*w1+y1)%m;
			w2=(x2*w2+y2)%m;
			count++;
		}
		cout<<count<<endl;
	}
}
