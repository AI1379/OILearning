#include<bits/stdc++.h>
using namespace std;
int n,x,y,maxx=-201,maxy=-201,minx=201,miny=201;
char m[201][201];
int main() {
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	cin>>n;
	memset(m,'.',sizeof(m));
	while(n--) {
		cin>>x>>y;
		x+=100,y+=100;
		m[x][y]='*';
		maxx=max(maxx,x),minx=min(minx,x);
		maxy=max(maxy,y),miny=min(miny,y);
	}
	if(maxx<100) maxx=100;
	if(minx>100) minx=100;
	if(maxy<100) maxy=100;
	if(miny>100) miny=100;
	for(int i=maxy; i>=miny; i--) m[100][i]=(m[100][i]=='*'?'*':'|');
	for(int i=maxx; i>=minx; i--) m[i][100]=(m[i][100]=='*'?'*':'-');
	m[100][100]='+';
	for(int i=maxy; i>=miny; i--) {
		for(int j=minx; j<=maxx; j++) cout<<m[j][i];
		cout<<endl;
	}
}
