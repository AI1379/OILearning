#include<bits/stdc++.h>
using namespace std;
int Map[10][10],x,y,v,n,a=0;
char c,l;
void g(){
	Map[x-1][y-1]=v;
	a++;
	if(c=='U'){
		for(int i=0;i<4;i++){
			bool f=false;
			int b=0;
			if(Map[0][i]!=0)
				b++;
			for(int j=1;j<4;j++){
				if(Map[j][i]!=0){
					if(Map[b-1][i]==Map[j][i]&&f==false){
						Map[b-1][i]*=2;
						f=true;
						a--;
					}
					else{
						f=false;
						Map[b][i]=Map[j][i];
						b++;
					}
					if(b-1!=j)
						Map[j][i]=0;
				}
			}
		}
	}
	else if(c=='D'){
		for(int i=0;i<4;i++){
			bool f=false;
			int b=3;
			if(Map[3][i]!=0)
				b--;
			for(int j=2;j>=0;j--){
				if(Map[j][i]!=0){
					if(Map[b+1][i]==Map[j][i]&&f==false){
						Map[b+1][i]*=2;
						f=true;
						a--;
					}
					else{
						f=false;
						Map[b][i]=Map[j][i];
						b--;
					}
					if(b+1!=j)
						Map[j][i]=0;
				}
			}
		}
	}
	else if(c=='L'){
		for(int i=0;i<4;i++){
			bool f=false;
			int b=0;
			if(Map[i][0]!=0)
				b++;
			for(int j=1;j<4;j++){
				if(Map[i][j]!=0){
					if(Map[i][b-1]==Map[i][j]&&f==false){
						Map[i][b-1]*=2;
						f=true;
						a--;
					}
					else{
						f=false;
						Map[i][b]=Map[i][j];
						b++;
					}
					if(b-1!=j)
						Map[i][j]=0;
				}
			}
		}
	}
	else if(c=='R'){
		for(int i=0;i<4;i++){
			bool f=false;
			int b=3;
			if(Map[i][3]!=0)
				b--;
			for(int j=2;j>=0;j--){
				if(Map[i][j]!=0){
					if(Map[i][b+1]==Map[i][j]&&f==false){
						Map[i][b+1]*=2;
						f=true;
						a--;
					}
					else{
						f=false;
						Map[i][b]=Map[i][j];
						b--;
					}
					if(b+1!=j)
						Map[i][j]=0;
				}
			}
		}
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%c%c",&x,&y,&v,&l,&c);
		g();
		if(a==16){
			printf("Game over!\n");
			return 0;
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			printf("%d ",Map[i][j]);
		printf("\n");
	}
	return 0;
}
