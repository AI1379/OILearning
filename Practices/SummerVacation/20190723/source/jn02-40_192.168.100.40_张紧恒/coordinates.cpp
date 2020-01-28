#include <bits/stdc++.h>
using namespace std;

const int o=100;
int n,maxx=o,maxy=o,minx=o,miny=o,x,y;
char a[201][201];

int main()
{
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	for(int i=o-100 ; i<=o+100 ; i++)
		for(int j=o-100 ; j<=o+100 ; j++)
			a[i][j]='.';
	for(int i=o-100 ; i<=o+100 ; i++)
		a[o][i]='|',a[i][o]='-';
	a[o][o]='+';
	cin>>n;
	for(int i=1 ; i<=n ; i++)
	{
		cin>>x>>y;
		a[x+o][y+o]='*';
		maxx=max(x+o,maxx);
		maxy=max(y+o,maxy);
		minx=min(x+o,minx);
		miny=min(y+o,miny);
	}
	for(int i=maxy ; i>=miny ; i--)
	{
		for(int j=minx ; j<=maxx ; j++)
			cout<<a[j][i];
		cout<<endl;
	}
	return 0;
}
