#include<bits/stdc++.h>
using namespace std;
int c[300][300]={};
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	int n,x[300],y[300],ix=1e9,iy=1e9,ax=-1e9,ay=-1e9,i,j;
	int a,b;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>y[i]>>x[i];
		b=y[i];
		a=x[i];
		c[a+100][b+100]=100;
		if(a+100>ax) ax=a+100;
		if(a+100<ix) ix=a+100;
		if(b+100>ay) ay=b+100;
		if(b+100<iy) iy=b+100;
	}
	ax=max(ax,100);
	ay=max(ay,100);
	ix=min(ix,100);
	iy=min(iy,100);
	for(i=ax;i>=ix;i--)
	{
		for(j=iy;j<=ay;j++)
		{
			if(c[i][j]==100) cout<<"*";
			else if(i==100&&j==100) cout<<"+";
			else if(i==100)cout<<"-";
			else if(j==100)cout<<"|";
			else cout<<".";
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
