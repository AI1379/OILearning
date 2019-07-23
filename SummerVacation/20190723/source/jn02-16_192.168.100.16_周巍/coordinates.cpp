#include<bits/stdc++.h>
using namespace std;
int n,maxx=-201,maxy=-201,minx=201,miny=201,L,R;
map<int ,char> a[201];
int main()
{
	freopen("coordinates .in","r",stdin);
	freopen("coordinates .out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	x+=100;
    	y+=100;
    	maxx=max(maxx,x);
    	minx=min(minx,x);
    	maxy=max(maxy,y);
    	miny=min(miny,y);
    	a[y][x]='*';
	}
	a[100][100]='+';
	for(int i=miny;i<=maxy;i++){
		if(a[i][100]!='+'&&a[i][100]!='*') a[i][100]='|';
	}
		for(int i=minx;i<=maxx;i++){
		if(a[100][i]!='+'&&a[100][i]!='*') a[100][i]='-';
	}
	for(int i=maxy;i>=miny;i--)
	{
		for(int j=minx;j<=maxx;j++)
		{
			if(a[i][j]!='*'&&a[i][j]!='+'&&a[i][j]!='|'&&a[i][j]!='-')
			cout<<'.';
			else cout<<a[i][j];
		}
		cout<<endl;
	}
	
	return 0;
}
