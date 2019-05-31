#include<bits/stdc++.h>
using namespace std;
int a[5][5],n;
bool check(){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			if(a[i][j]==0) return true; 
		}
	}
	return false;
} 
const int INF=1<<30;
int main(){
	freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=4;i++) a[i][0]=INF/3,a[0][i]=INF/3;
	for(int i=1;i<=n;i++){
		int x,y,v;
		char f;
		cin>>x>>y>>v>>f;
		a[x][y]=v;
		if(f=='R'){
			for(int j=4;j>=1;j--){
					for(int k=j+1;k<=4;k++){
						if(a[i][k]==0&&a[i][j]!=0){
							a[i][k]=a[i][j];
							a[i][j]=0;
							j=k;
						}
					}
				}
			for(int i=1;i<=4;i++){
				for(int j=4;j>1;j--){
					if(a[i][j]==a[i][j-1]){
						a[i][j]+=a[i][j-1];
						a[i][j-1]=0;
						
					}
					
				}
				for(int j=4;j>=1;j--){
					for(int k=j+1;k<=4;k++){
						if(a[i][k]==0&&a[i][j]!=0){
							a[i][k]=a[i][j];
							a[i][j]=0;
							j=k;
						}
					}
				}
			}
			if(!check()){
				cout<<"Game over!";
				return 0;
			}
		}
		if(f=='L'){
			for(int j=1;j<=4;j++){
					for(int k=j-1;k>=1;k--){
						if(a[i][k]==0&&a[i][j]!=0){
							a[i][k]=a[i][j];
							a[i][j]=0;
							j=k;
						}
					}
				}
			for(int i=1;i<=4;i++){
				for(int j=1;j<4;j++){
					if(a[i][j]==a[i][j+1]){
						a[i][j]+=a[i][j+1];
						a[i][j+1]=0;
					    }
					    for(int j=1;j<=4;j++){
					for(int k=j-1;k>=1;k--){
						if(a[i][k]==0&&a[i][j]!=0){
							a[i][k]=a[i][j];
							a[i][j]=0;
							j=k;
						}
					}
				}
					    
				}
			}
			if(!check()){
				cout<<"Game over!";
				return 0;
			}
		}
		if(f=='U'){
			for(int i=1;i<=4;i++){
				for(int j=1;j<=4;j++){
					for(int k=j-1;k>=1;k--){
						if(a[k][i]==0&&a[j][i]!=0){
							a[k][i]=a[j][i];
							a[j][i]=0;
							j=k;
						}
					}
				}
				for(int j=1;j<4;j++){
					if(a[j][i]==a[j+1][i]){
						a[j][i]+=a[j+1][i];
						a[j+1][i]=0;
						
					}
					
				}
				for(int j=1;j<=4;j++){
					for(int k=j-1;k>=1;k--){
						if(a[k][i]==0&&a[j][i]!=0){
							a[k][i]=a[j][i];
							a[j][i]=0;
							j=k;
						}
					}
				}
			}
			if(!check()){
				cout<<"Game over!";
				return 0;
			}
		}
		if(f=='D'){
			for(int j=4;j>=1;j--){
					for(int k=j+1;k<=4;k++){
						if(a[k][i]==0&&a[j][i]!=0){
							a[k][i]=a[j][i];
							a[j][i]=0;
							j=k;
						}
					}
				}
			for(int i=1;i<=4;i++){
				for(int j=4;j>1;j--){
					if(a[j][i]==a[j-1][i]){
						a[j][i]+=a[j-1][i];
						a[j-1][i]=0;
						
					}
					
				}
				for(int j=4;j>=1;j--){
					for(int k=j+1;k<=4;k++){
						if(a[k][i]==0&&a[j][i]!=0){
							a[k][i]=a[j][i];
							a[j][i]=0;
							j=k;
						}
					}
				}
			}
			if(!check()){
				cout<<"Game over!";
				return 0;
			}
		}
		
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
