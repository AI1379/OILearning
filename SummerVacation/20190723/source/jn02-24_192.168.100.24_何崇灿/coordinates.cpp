#include<bits/stdc++.h>
using namespace std;
int d[210],n,x[260],y[260],t=0;
int r=100,l=100,o=100,u=100;
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) 
	{
		cin >> x[i]>>y[i];
		x[i]+=100;
		y[i]+=100;
		if(x[i]<l)l=x[i];
		if(x[i]>r)r=x[i];
		if(y[i]<u)u=y[i];
		if(y[i]>o)o=y[i];
	}
	for(int j=o;j>=u;j--)
	{
		for(int i=l;i<=r;i++)
		{
		t=0;
			for(int v=1;v<=n;v++)
	    	{
	    		if(x[v]==i&&y[v]==j) cout<<"*",t++;
			}
		    if(t==0)
		    {
			    if(i==100&&j==100) cout<<"+";
	            else if(i!=100&&j==100)cout<<"-";
	            else if(i==100&&j!=100) cout<<"|";
	            else cout<<".";
		    }
		}
	cout<<endl;
	} 
    return 0;
}
