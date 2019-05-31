#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T> inline void read(T&x) {
    char ch=getchar();
    x=0;
    bool f=0;
    for(; ch<'0'||ch>'9'; ch=getchar())if(ch=='-')f=1;
    for(; ch>='0'&&ch<='9'; x=(x<<1)+(x<<3)+(ch&15),ch=getchar());
    if(f)x=-x;
}
template<typename T> inline void write(T x) {
    if(x<0)x=-x,putchar('-');
    if(x>9)write(x/10);
    putchar(x%10|48);
}
template<typename T> inline void writeln(T x) {
    write(x),putchar('\n');
}
int n;
int a[10][10];
inline char get(){
	char c=getchar();
	while(c!='L'&&c!='R'&&c!='D'&&c!='U')c=getchar();
	return c;
}
inline bool judge(){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			if(a[i][j])return 0;
		}
	}
	return 1;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		int x,y,v;
		read(x),read(y),read(v);
		char c=get();
		a[x][y]=v;
		if(c=='L'){
			//for(int i=1;i<=3;i++)
			for(int l=1;l<=4;l++)
			for(int i=1;i<=4;i++)for(int k=1;k<=4;k++){
				if(a[i][k]==0){
					for(int j=k;j<=4;j++)a[i][j]=a[i][j+1];
				}
			}
			for(int l=1;l<=3;l++)
			for(int k=1;k<=4;k++){
				if(a[k][l]==a[k][l+1]){
					a[k][l]<<=1;
					for(int j=l+1;j<4;j++)a[k][j]=a[k][j+1];
					a[k][4]=0;
				}
			}
		}
		if(c=='R'){
			//for(int i=4;i>=2;i--)
			for(int l=1;l<=4;l++)
			for(int i=1;i<=4;i++)for(int k=4;k>=1;k--){
				if(a[i][k]==0){
					for(int j=k;j>=1;j--)a[i][j]=a[i][j-1];
				}
			}
			for(int l=4;l>=2;l--)
			for(int k=1;k<=4;k++){
				if(a[k][l]==a[k][l-1]){
					a[k][l]<<=1;
					for(int j=l-1;j>1;j--)a[k][j]=a[k][j-1];
					a[k][1]=0;
				}
			}
		}
		if(c=='U'){
			//for(int i=1;i<=3;i++)
			for(int l=1;l<=4;l++)
			for(int i=1;i<=4;i++)for(int k=4;k>=1;k--){
				if(a[i][k]==0){
					for(int j=i;j<=4;j++)a[j][k]=a[j+1][k];
				}
			}
			for(int l=1;l<=3;l++)
			for(int k=1;k<=4;k++){
				if(a[l][k]==a[l+1][k]){
					a[l][k]<<=1;
					for(int j=l+1;j<4;j++)a[j][k]=a[j+1][k];
					a[4][k]=0;
				}
			}
		}
		if(c=='D'){
			//for(int i=4;i>=2;i--)
			for(int l=1;l<=4;l++)
			for(int i=1;i<=4;i++)for(int k=4;k>=1;k--){
				if(a[i][k]==0){
					for(int j=i;j>=1;j--)a[j][k]=a[j-1][k];
				}
			}
			for(int l=4;l>=2;l--)
			for(int k=1;k<=4;k++){
				if(a[l][k]==a[l-1][k]){
					a[l][k]<<=1;
					for(int j=l-1;j>1;j--)a[j][k]=a[j-1][k];
					a[1][k]=0;
				}
			}
		}
		//puts(" ");
		//for(int i=1;i<=4;i++,putchar('\n'))
		//for(int j=1;j<=4;j++)printf("%d ",a[i][j]);
		//puts("");
		if(judge()){
			puts("Game over!");
			return 0;
		}
	}
	for(int i=1;i<=4;i++,putchar('\n'))
		for(int j=1;j<=4;j++)printf("%d ",a[i][j]);
	return 0;
}
/*
  1 2 3 4
  
1 4 0 4 0
2 0 0 0 2
3 2 0 0 0
4 2 2 0 0
*/
