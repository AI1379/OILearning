#include<bits/stdc++.h>
using namespace std;
int n,x,y,ma[400][400],xma=100,xmi=100,yma=100,ymi=100;
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>x>>y;
		xma=max(x+100,xma);
		xmi=min(x+100,xmi);
		yma=max(y+100,yma);
		ymi=min(y+100,ymi);
		ma[x+100][y+100]=1;
	}
	for(int i=yma;i>=ymi;i--)
	{
		for(int j=xmi;j<=xma;j++)
		{
		if(ma[j][i])cout<<'*';
		else
		{
			if(i==100&&j!=100)cout<<'-';
			if(i!=100&&j==100)cout<<'|';
			if(i==100&&j==100)cout<<'+';
			if(i!=100&&j!=100)cout<<'.';}
		}
		cout<<endl;
	}
	return 0;
}
