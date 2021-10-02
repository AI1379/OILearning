#include<bits/stdc++.h>
using namespace std;
int main()
{   freopen("coordinates.in","r",stdin);
    freopen("coordinates.out","w",stdout);
	int n,a,b,c,d,e,g,minx=101,miny=101,maxx=-101,maxy=-101;
	int x[300],y[300];
	bool w[251][251];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>x[i]>>y[i];
	if(x[i]<minx) minx=x[i];
	if(x[i]>maxx) maxx=x[i];
	if(y[i]<miny) miny=y[i];
	if(y[i]>maxy) maxy=y[i];
	w[x[i]+100][y[i]+100]=true;
    } 
    //cout<<minx<<" "<<maxy;
    //cout<<w[minx+100][maxy+100];
    minx=min(minx,0);
    miny=min(miny,0);
    maxx=max(maxx,0);
    maxy=max(maxy,0);
    //cout<<minx<<" "<<maxy;
    for(int i=maxy;i>=miny;i--)
    for(int j=minx;j<=maxx;j++)
    {   if(w[j+100][i+100]==true) cout<<"*";
        else if(i==0&&j==0) cout<<"+";
    	else if(i!=0&&j!=0&&w[j+100][i+100]==false) cout<<".";
    	else if(i==0&&j!=0) cout<<"-";
    	else if(i!=0&&j==0) cout<<"|";
    	if(j==maxx) cout<<endl;
	}
}
