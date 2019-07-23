#include<bits/stdc++.h>
using namespace std;
int n,x[300],y[300],a,b,a1,b1,a2,b2;
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		a1=max(a1,x[i-1]);
		a2=min(a2,x[i-1]);
		b1=max(b1,y[i-1]);
		b2=min(b2,y[i-1]);
	}
	a=a1-a2+1; b=b1-b2+1;
	int s[a+1][b+1]={false};
	for (int i=1;i<=n;i++)
	{
		s[x[i]-a2+1][y[i]-b2+1]=true;
	}
	for (int i=1;i<=a;i++)
	{
		for (int j=1;j<=b;j++)
		{
			if (i+b2==1&&j+a2==1) cout<<'+';
			else if (i+b2==1) cout<<'|';
			else if (j+a2==1) cout<<'-';
			else if (s[i][j]==true) cout<<'*';
			else if (s[i][j]==false) cout<<'.';
		}
		cout<<endl;
	}
	return 0;
}
