#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define For(i,j,k) for (int i=j;i<=k;++i)
#define foR(i,j,k) for (int i=j;i>=k;--i)
#define mem(a,x) memset(a,x,sizeof(a))
#define sqr(x) (x)*(x)
template <typename T>void cmin(T &a,T b){a=min(a,b);}
template <typename T>void cmax(T &a,T b){a=max(a,b);}
template <typename T>
void read(T &x){
	char c;T f=1;
	while (!isdigit(c=getchar())) if (c=='-') f=-1;
	x=c-'0';
	while (isdigit(c=getchar())) x=x*10+c-'0';
	x*=f;
}
int n,a[10][10];
int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	read(n);
	For (i,1,n){
		int x,y,v;char c;
		read(x),read(y),read(v),c=getchar();
		if (a[x][y]) {printf("Game over!\n");return 0;}
		a[x][y]=v;
		if (c=='L'){
			For (i,1,4){
				int l=1;
				For (j,1,4)
					if (a[i][j])
						{int te=a[i][j];a[i][j]=0,a[i][l++]=te;}
				if (a[i][1]==a[i][2]){
					a[i][1]<<=1,a[i][2]=a[i][3],a[i][3]=a[i][4],a[i][4]=0;
					if (a[i][2]==a[i][3])
						a[i][2]<<=1,a[i][3]=0;
				}
					else if (a[i][2]==a[i][3])
							a[i][2]<<=1,a[i][3]=a[i][4],a[i][4]=0;
							else if (a[i][3]==a[i][4])
									a[i][3]<<=1,a[i][4]=0;
			}
		}
		if (c=='R'){
			For (i,1,4){
				int r=4;
				foR (j,4,1)
					if (a[i][j])
						{int te=a[i][j];a[i][j]=0,a[i][r--]=te;}
				if (a[i][4]==a[i][3]){
					a[i][4]<<=1,a[i][3]=a[i][2],a[i][2]=a[i][1],a[i][1]=0;
					if (a[i][3]==a[i][2])
						a[i][3]<<=1,a[i][2]=0;
				}
					else if (a[i][3]==a[i][2])
							a[i][3]<<=1,a[i][2]=a[i][1],a[i][1]=0;
							else if (a[i][2]==a[i][1])
									a[i][2]<<=1,a[i][1]=0;
			}
		}
		if (c=='U'){
			For (i,1,4){
				int u=1;
				For (j,1,4)
					if (a[j][i])
						{int te=a[j][i];a[j][i]=0,a[u++][i]=te;}
				if (a[1][i]==a[2][i]){
					a[1][i]<<=1,a[2][i]=a[3][i],a[3][i]=a[4][i],a[4][i]=0;
					if (a[2][i]==a[3][i])
						a[2][i]<<=1,a[3][i]=0;
				}
					else if (a[2][i]==a[3][i])
							a[2][i]<<=1,a[3][i]=a[4][i],a[4][i]=0;
							else if (a[3][i]==a[4][i])
									a[3][i]<<=1,a[4][i]=0;
			}
		}
		if (c=='D'){
			For (i,1,4){
				int d=4;
				foR (j,4,1)
					if (a[j][i])
						{int te=a[j][i];a[j][i]=0,a[d--][i]=te;}
				if (a[4][i]==a[3][i]){
					a[4][i]<<=1,a[3][i]=a[2][i],a[2][i]=a[1][i],a[1][i]=0;
					if (a[3][i]==a[2][i])
						a[3][i]<<=1,a[2][i]=0;
				}
					else if (a[3][i]==a[2][i])
							a[3][i]<<=1,a[2][i]=a[1][i],a[1][i]=0;
							else if (a[2][i]==a[1][i])
									a[2][i]<<=1,a[1][i]=0;
			}
		}
	}
	For (i,1,4) printf("%d %d %d %d\n",a[i][1],a[i][2],a[i][3],a[i][4]);
	return 0;
}

