#include<bits/stdc++.h>
using namespace std;
int fz[6][6];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	for(int i=0;i<=5;i++)fz[i][0]=fz[i][5]=1;
	for(int j=0;j<=5;j++)fz[0][j]=fz[5][j]=1;
	int n,x,y,v,t,tt,zs=0;
	char c;
	cin>>n;
	for(int T=1;T<=n;T++){
		cin>>x>>y>>v>>c;
		fz[x][y]=v;
		zs++;
		switch(c){
			case 'U':
				for(int j=1;j<=4;j++){
					for(int i=1;i<=4;i++){
						if(fz[i][j]!=0){
							t=fz[i][j];
							fz[i][j]=0;
							tt=i;
							while(fz[tt][j]==0)tt--;
							if(fz[tt][j]==t)fz[tt][j]+=t,zs--;
							else fz[tt+1][j]=t;
						}
					}
				}
				break;
			case 'D':
				for(int j=1;j<=4;j++){
					for(int i=4;i>=1;i--){
						if(fz[i][j]!=0){
							t=fz[i][j];
							fz[i][j]=0;
							tt=i;
							while(fz[tt][j]==0)tt++;
							if(fz[tt][j]==t)fz[tt][j]+=t,zs--;
							else fz[tt-1][j]=t;
						}
					}
				}
				break;
			case 'L':
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++){
						if(fz[i][j]!=0){
							t=fz[i][j];
							fz[i][j]=0;
							tt=j;
							while(fz[i][tt]==0)tt--;
							if(fz[i][tt]==t)fz[i][tt]+=t,zs--;
							else fz[i][tt+1]=t;
						}
					}
				}
				break;
			case 'R':
				for(int i=1;i<=4;i++){
					for(int j=4;j>=1;j--){
						if(fz[i][j]!=0){
							t=fz[i][j];
							fz[i][j]=0;
							tt=j;
							while(fz[i][tt]==0)tt++;
							if(fz[i][tt]==t)fz[i][tt]+=t,zs--;
							else fz[i][tt-1]=t;
						}
					}
				}
				break;
		}
		if(zs==16){
			cout<<"Game over!";
			return 0;
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			printf("%d ",fz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
