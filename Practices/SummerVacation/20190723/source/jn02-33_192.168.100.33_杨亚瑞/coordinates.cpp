#include<bits/stdc++.h>
using namespace std;char m[201][201];int a[251];int b[251];
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	int n;int x1=0;int x2=0;int y1=0;int y2=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[i]=x;b[i]=y;
		if(x<x1) x1=x;
		if(x>x2) x2=x;
		if(y<y1) y1=y;
		if(y>y2) y2=y;
	}
	for(int j=0;j<=x2-x1;j++)
	{
		m[j][y2]='-';
	}

	for(int k=0;k<=y2-y1;k++)
	{
		m[-x1][k]='|';
	}
	for(int i=1;i<=n;i++)
	{
	   m[a[i]-x1][y2-b[i]]='*';	
	}	
	m[-x1][y2]='+';
	for(int p=0;p<=y2-y1;p++)
	{
		for(int u=0;u<=x2-x1;u++)
	{
		if(m[u][p]=='*'||m[u][p]=='+'||m[u][p]=='-'||m[u][p]=='|')
		cout<<m[u][p];
		else
		cout<<".";
	}
	cout<<endl;
	}
	return 0;
}
