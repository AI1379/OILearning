#include<bits/stdc++.h>
using namespace std;
int n,maxx,minx,maxy,miny,x[251],y[251];
int a[201][201];
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		if(x[i]>maxx)maxx=x[i];
		if(x[i]<minx)minx=x[i];
		if(y[i]>maxy)maxy=y[i];
		if(y[i]<miny)miny=y[i];
	}
	for(int i=1;i<=n;i++)
	a[maxy-y[i]+1][x[i]-minx+1]=1;
	for(int i=1;i<=maxy-miny+1;i++)
	{
		for(int j=1;j<=maxx-minx+1;j++)
	 	{
	 	if(i==maxy+1&&j==-minx+1)cout<<"+";
	 	else if(a[i][j])cout<<"*";
	 	else if(i==maxy+1)cout<<"-";
	 	else if(j==-minx+1)cout<<"|";
	 	else cout<<".";
	 	}
	 	cout<<endl;
	}
	 return 0;
}
