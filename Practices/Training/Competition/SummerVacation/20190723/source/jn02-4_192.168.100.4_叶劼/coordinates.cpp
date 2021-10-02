#include<bits/stdc++.h>
using namespace std;
int n,x[251],y[251],maxx=-1e9,minx=1e9,maxy=-1e9,miny=1e9,tx,ty,midx,midy;
char a[201][201];
int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>x[i]>>y[i];
		maxx=max(maxx,x[i]);
		minx=min(minx,x[i]);
		maxy=max(maxy,y[i]);
		miny=min(miny,y[i]);
	}
	maxx=max(maxx,0);
	maxy=max(maxy,0);
	minx=min(minx,0);
	miny=min(miny,0);
	tx=maxx-minx+1;
	ty=maxy-miny+1;
	midx=abs(minx)+1;
	midy=ty+miny;
	for(int i=1;i<=ty;i++)
	    for(int j=1;j<=tx;j++)
	        if(i==midy && j==midx)
	            a[i][j]='+';
	        else
	            if(i==midy)
	                a[i][j]='-';
	            else
	                if(j==midx)
	                    a[i][j]='|';
	                else
	                    a[i][j]='.';
	for(int i=1;i<=n;i++)
	    a[midy-y[i]][midx+x[i]]='*';
	for(int i=1;i<=ty;i++)
	{
	    for(int j=1;j<=tx;j++)
	        cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}
