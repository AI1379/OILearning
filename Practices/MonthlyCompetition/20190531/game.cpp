#include<bits/stdc++.h>
using namespace std;
long long mat[5][5],n;
bool operate(char c){
	int i,j,k;
	bool flag=false;
	for(i=1;i<=4;i++)
		for(j=1;j<=4;j++)
			if(mat[i][j]==0)
				flag=true;
	if(!flag)return false;
	if(c=='L'){
		for(i=1;i<=4;i++){
			for(j=2;j<=4;j++){
				k=j;
				while(k>1){
					if(mat[i][k-1]==mat[i][k]){
						mat[i][k-1]+=mat[i][k];
						mat[i][k]=0;
						break;
					}
					else if(mat[i][k-1]==0){
						mat[i][k-1]=mat[i][k];
						mat[i][k]=0;
					}
					k--;
				}
			}
		}
	}
	else if(c=='R'){
		for(i=1;i<=4;i++){
			for(j=3;j>=1;j--){
				k=j;
				while(k<4){
					if(mat[i][k+1]==mat[i][k]){
						mat[i][k+1]+=mat[i][k];
						mat[i][k]=0;
						break;
					}
					else if(mat[i][k+1]==0){
						mat[i][k+1]=mat[i][k];
						mat[i][k]=0;
					}
					k++;
				}
			}
		}
	}
	else if(c=='U'){
		for(i=1;i<=4;i++){
			for(j=2;j<=4;j++){
				k=j;
				while(k>1){
					if(mat[k-1][i]==mat[k][i]){
						mat[k-1][i]+=mat[k][i];
						mat[k][i]=0;
						break;
					}
					else if(mat[k-1][i]==0){
						mat[k-1][i]=mat[k][i];
						mat[k][i]=0;
					}
					k--;
				}
			}
		}
	}
	else if(c=='D'){
		for(i=1;i<=4;i++){
			for(j=3;j>=1;j--){
				k=j;
				while(k<4){
					if(mat[k+1][i]==mat[k][i]){
						mat[k+1][i]+=mat[k][i];
						mat[k][i]=0;
						break;
					}
					else if(mat[k+1][i]==0){
						mat[k+1][i]=mat[k][i];
						mat[k][i]=0;
					}
					k++;
				}
			}
		}
	}
	return true;
}
int main(){
	int x,y,v,i,j,k;
	char c;
	cin>>n;
	for(k=0;k<n;k++){
		cin>>x>>y>>v>>c;
		mat[x][y]=v;
		if(!operate(c)){
			cout<<"Game over!";
			return 0;
		}
	}
	for(i=1;i<=4;i++){
		for(j=1;j<=4;j++){
			cout<<mat[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
