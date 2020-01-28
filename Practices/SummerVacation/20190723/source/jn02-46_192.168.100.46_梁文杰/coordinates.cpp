#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int x[255],y[255],maxx,minx,maxy,miny,n;
char a[520][520];
int main()
{
//	freopen("coordinates.in","r",stdin);
//	freopen("coordinates.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		maxx=max(maxx,x[i]);
		minx=min(minx,x[i]);
		maxy=max(maxy,y[i]);
		miny=min(miny,y[i]);
	}
	for (int i=maxy;i>=miny;i--){
		for (int j=maxx;j>=minx;j--){
		    if (i==0&&j==0)
				a[i+100][j+100]='+';
			else if (i==0)
				a[i+100][j+100]='-';
			else if (j==0)
				a[i+100][j+100]='|';
			else a[i+100][j+100]='.';
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
				a[x[i]][y[i]]='*';
		}
	for (int i=maxy+100;i>=miny+100;i--){
		for (int j=maxx+100;j>=minx+100;j--){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}

