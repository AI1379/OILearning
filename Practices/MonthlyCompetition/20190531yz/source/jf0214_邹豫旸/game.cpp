#include<bits/stdc++.h>
using namespace std;
struct gj{
	int len;
	int a[50];
};
gj f[6][6];
int n;
void p(int x,int y){
	for(int i=f[x][y].len; i>=1; i--) cout<<f[x][y].a[i];
	cout<<" ";
}
bool nz(int x,int y){
	if(f[x][y].len==1&&f[x][y].a[1]==0) return 0;
	else return 1;
}
void tz(int x,int y){
	for(int i=1; i<=50; i++) f[x][y].a[i]=0;
	f[x][y].len=1;
}
bool e(gj a,gj b){
	if(a.len!=b.len) return 0;
	for(int i=1; i<=a.len; i++){
		if(a.a[i]!=b.a[i]) return 0;
	}
	return 1;
}
void t(int x,int y){
	for(int i=1; i<=f[x][y].len; i++) f[x][y].a[i]*=2;
	for(int i=1; i<=f[x][y].len; i++){
		if(f[x][y].a[i]>9){
			f[x][y].a[i+1]=f[x][y].a[i+1]+f[x][y].a[i]/10;
			if(i==f[x][y].len) f[x][y].len++;
		}
	}
}
void m(char c){
	if(c=='L'){
		for(int jj=2; jj<=4; jj++){
			for(int ii=1; ii<=4; ii++){
				int i=ii,j=jj;
				if(nz(i,j)){
					while(!(nz(i,j-1))&&(i<=4)&&(i>=1)&&(j-1>=1)&&(j-1<=4)){
						swap(f[i][j],f[i][j-1]);
						j--;
					}
					if(nz(i,j-1)){
						if(e(f[i][j],f[i][j-1])){
							tz(i,j);
							t(i,j-1);
						}
					}
				}
			}
		}
	}
	if(c=='R'){
		for(int jj=3; jj>=1; jj--){
			for(int ii=1; ii<=4; ii++){
				int i=ii,j=jj;
				if(nz(i,j)){
					while(!(nz(i,j+1))&&(i<=4)&&(i>=1)&&(j+1>=1)&&(j+1<=4)){
						swap(f[i][j],f[i][j+1]);
						j++;
					} 
					if(nz(i,j+1)){
						if(e(f[i][j],f[i][j+1])){
							tz(i,j);
							t(i,j+1);
						}
					}
				}
			}
		}
	}
	if(c=='U'){
		for(int ii=2; ii<=4; ii++){
			for(int jj=1; jj<=4; jj++){
				int i=ii,j=jj;
				if(nz(i,j)){
					while(!(nz(i-1,j))&&(i-1<=4)&&(i-1>=1)&&(j>=1)&&(j<=4)){
						swap(f[i][j],f[i-1][j]);
						i--;
					} 
					if(nz(i-1,j)){
						if(e(f[i][j],f[i-1][j])){
							tz(i,j);
							t(i-1,j);
						}
					}
				}
			}
		}
	}
	if(c=='D'){
		for(int ii=3; ii>=1; ii--){
			for(int jj=1; jj<=4; jj++){
				int i=ii,j=jj;
				if(nz(i,j)){
				    while(!(nz(i+1,j))&&(i+1<=4)&&(i+1>=1)&&(j>=1)&&(j>=1)){
						swap(f[i][j],f[i+1][j]);
						i++;
					} 
					if(e(f[i][j],f[i+1][j])){
						tz(i,j);
						t(i+1,j);
					}
				}
			}
		}
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1; i<=4; i++){
		for(int j=1; j<=4; j++) tz(i,j);
	}
	for(int i=1; i<=n; i++){
		int x,y; string s; char c;
		cin>>x>>y>>s>>c;
		f[x][y].a[1]=(s[0]-'0');
		m(c); 
	}
	cout<<"Game over!";
	return 0;
	for(int i=1; i<=4; i++){
		for(int j=1; j<=4; j++){
			p(i,j);
		}
		cout<<endl;
	}
	return 0;
}
