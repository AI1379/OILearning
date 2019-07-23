//#include<bits/stdc++.h>
#include<cstdio>
//#include<>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
//using namespace std;
inline int read(){
	register int x;register char c(getchar());register bool k;
	//while((c<'0'||c>'9')&&c^'-')if((c=getchar())==EOF)exit(0);
	if(c^'-')x=c-'0',k=1;else x=0,k=0;
	for(c=getchar();c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return k?x:((~x)+1);
}
char Map[201][201]={};
int n,x,y,nx=100,ny=100,xx=100,xy=100;
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	for(int i=0;i<=200;i++)
		for(int j=0;j<=200;j++)
			Map[i][j]='.';
	for(int i=0;i<=200;i++)
		Map[i][100]='-';
	for(int j=0;j<=200;j++)
		Map[100][j]='|';
	Map[100][100]='+';
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		y=-y;
		x+=100,y+=100;
		Map[x][y]='*';
		nx=Min(nx,x);
		ny=Min(ny,y);
		xx=Max(xx,x);
		xy=Max(xy,y);
	}
	for(int j=ny;j<=xy;j++){
		for(int i=nx;i<=xx;i++){
			putchar(Map[i][j]);
		}
		putchar('\n');
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
