#include<bits/stdc++.h>
using namespace std;
const int MAXN=5;
int N,a[MAXN][MAXN],x,y,v,tot;
char f;
void movement(char op){
	int tmp=0;
	if (op=='U'){
		for (int i=1;i<=4;i++){
			tmp=0;
			for (int j=1;j<=4;j++)
				if (a[j][i]){
					a[++tmp][i]=a[j][i];
					if (j!=tmp) a[j][i]=0;
				}
		}
	}
	if (op=='D'){
		for (int i=1;i<=4;i++){
			tmp=0;
			for (int j=4;j>=1;j--)
				if (a[j][i]){
					a[4-(++tmp)+1][i]=a[j][i];
					if (j!=(4-tmp+1)) a[j][i]=0;
				}
		}
	}
	if (op=='L'){
		for (int i=1;i<=4;i++){
			tmp=0;
			for (int j=1;j<=4;j++)
				if (a[i][j]){
					a[i][++tmp]=a[i][j];
					if (j!=tmp) a[i][j]=0;
				}
		}
	}
	if (op=='R'){
		for (int i=1;i<=4;i++){
			tmp=0;
			for (int j=4;j>=1;j--)
				if (a[i][j]){
					a[i][4-(++tmp)+1]=a[i][j];
					if (j!=(4-tmp+1)) a[i][j]=0;
				}
		}
	}
}
void mergesame(char op){
	if (op=='U'){
		for (int i=1;i<=4;i++)
			for (int j=1;j<=3;j++)
				if (a[j][i]==a[j+1][i]) a[j][i]*=2,a[j+1][i]=0;
	}
	if (op=='D'){
		for (int i=1;i<=4;i++)
			for (int j=4;j>=2;j--)
				if (a[j][i]==a[j-1][i]) a[j][i]*=2,a[j-1][i]=0;
	}
	if (op=='L'){
		for (int i=1;i<=4;i++)
			for (int j=1;j<=3;j++)
				if (a[i][j]==a[i][j+1]) a[i][j]*=2,a[i][j+1]=0;
	}
	if (op=='R'){
		for (int i=1;i<=4;i++)
			for (int j=4;j>=2;j--)
				if (a[i][j]==a[i][j-1]) a[i][j]*=2,a[i][j-1]=0;
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;i++){
		cin>>x>>y>>v>>f;
		a[x][y]=v;
		movement(f);
		mergesame(f);
		movement(f);
	}
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
			if (a[i][j]) tot++;
	if (tot==16) printf("Game over!");
	else{
		for (int i=1;i<=4;i++){
			for (int j=1;j<=4;j++) printf("%d ",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
