#include<bits/stdc++.h>
using namespace std;
const int MAXN=255;
int N,x,y,maxx,minx,maxy,miny;
bool f[MAXN][MAXN];
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	scanf("%d",&N);
	maxx=maxy=-105,minx=miny=105;
	for (int i=1;i<=N;i++){
		scanf("%d%d",&x,&y),f[x+105][y+105]=true;
		maxx=max(maxx,x),minx=min(minx,x);
		maxy=max(maxy,y),miny=min(miny,y);
	}
	maxx=max(maxx,0),maxy=max(maxy,0);
	minx=min(minx,0),miny=min(miny,0);
	for (int i=maxy;i>=miny;i--){
		for (int j=minx;j<=maxx;j++){
			if (i==0&&j==0) printf("+");
			else if (f[j+105][i+105]) printf("*");
			else if (i==0) printf("-");
			else if (j==0) printf("|");
			else printf(".");
		}
		printf("\n");
	}
	return 0;
}
