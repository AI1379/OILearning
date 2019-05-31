#include<bits/stdc++.h>
using namespace std;
long long f[5][5];
int n,x,y,v;
char q;
bool xx=false;
void shang() {
	for(int i=2; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			if(f[i][j]==0) continue;
			else if(f[i-1][j]==0&&f[i][j]!=0) {
				int a=i-1,b=j;
				while(f[a-1][b]==0&&a>=2) {
					a--;
				}
				f[a][b]=f[i][j];
				f[i][j]=0;
			}
		}
	}
	for(int i=2; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			if(f[i][j]==f[i-1][j]) f[i-1][j]*=2,f[i][j]=0;
		}
	}
	for(int i=2; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			if(f[i][j]==0) continue;
			else if(f[i-1][j]==0&&f[i][j]!=0) {
				int a=i-1,b=j;
				while(f[a-1][b]==0&&a>=2) {
					a--;
				}
				f[a][b]=f[i][j];
				f[i][j]=0;
			}
		}
	}
}
void xia() {
	for(int i=3; i>=1; i--) {
		for(int j=1; j<=4; j++) {
			if(f[i][j]==0) continue;
			else if(f[i+1][j]==0&&f[i][j]!=0) {
				int a=i+1,b=j;
				while(f[a+1][b]==0&&a<=3) {
					a++;
				}
				f[a][b]=f[i][j];
				f[i][j]=0;
			}
		}
	}
	for(int i=3; i>=1; i--) {
		for(int j=1; j<=4; j++) {
			if(f[i][j]==f[i+1][j]) f[i+1][j]*=2,f[i][j]=0;
		}
	}
	for(int i=3; i>=1; i--) {
		for(int j=1; j<=4; j++) {
			if(f[i][j]==0) continue;
			else if(f[i+1][j]==0&&f[i][j]!=0) {
				int a=i+1,b=j;
				while(f[a+1][b]==0&&a<=3) {
					a++;
				}
				f[a][b]=f[i][j];
				f[i][j]=0;
			}
		}
	}
}
void zuo() {
	for(int i=2; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			if(f[j][i]==0) continue;
			else if(f[j][i-1]==0&&f[j][i]!=0) {
				int a=j,b=i-1;
				while(f[a][b-1]==0&&b>=2) {
					b--;
				}
				f[a][b]=f[j][i];
				f[j][i]=0;
			}
		}
	}
	for(int i=2; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			if(f[j][i]==f[j][i-1]) f[j][i-1]*=2,f[j][i]=0;
		}
	}
	for(int i=2; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			if(f[j][i]==0) continue;
			else if(f[j][i-1]==0&&f[j][i]!=0) {
				int a=j,b=i-1;
				while(f[a][b-1]==0&&b>=2) {
					b--;
				}
				f[a][b]=f[j][i];
				f[j][i]=0;
			}
		}
	}
}
void you() {
	for(int i=3; i>=1; i--) {
		for(int j=1; j<=4; j++) {
			if(f[j][i]==0) continue;
			else if(f[j][i+1]==0&&f[j][i]!=0) {
				int a=j,b=i+1;
				while(f[a][b+1]==0&&b<=3) {
					b++;
				}
				f[a][b]=f[j][i];
				f[j][i]=0;
			}
		}
	}
	for(int i=2; i<=4; i++) {
		for(int j=1; j<=4; j++) {
			if(f[j][i]==f[j][i+1]) f[j][i+1]*=2,f[j][i]=0;
		}
	}
	for(int i=3; i>=1; i--) {
		for(int j=1; j<=4; j++) {
			if(f[j][i]==0) continue;
			else if(f[j][i+1]==0&&f[j][i]!=0) {
				int a=j,b=i+1;
				while(f[a][b+1]==0&&b<=3) {
					b++;
				}
				f[a][b]=f[j][i];
				f[j][i]=0;
			}
		}
	}
}
void p() {
	for(int i=1; i<=4; i++) {
		for(int j=1; j<=4; j++) cout<<f[i][j]<<" ";
		cout<<endl;
	}
}
int main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		xx=true;
		cin>>x>>y>>v>>q;
		f[x][y]=v;
		switch(q) {
			case 'U': {
				shang();
				break;
			}
			case 'D': {
				xia();
				break;
			}
			case 'L': {
				zuo();
				break;
			}
			case 'R': {
				you();
				break;
			}
		}
		for(int i=1; i<=4; i++) {
			for(int j=1; j<=4; j++) {
				if(f[i][j]==0) xx=false;
			}
		}
		if(xx){
			cout<<"Game over!";
			return 0;
		}
	}
	p();
	return 0;
}
