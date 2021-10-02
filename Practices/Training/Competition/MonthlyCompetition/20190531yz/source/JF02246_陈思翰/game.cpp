#include<bits/stdc++.h>
using namespace std;
int a[5][5],n,x,y,z;
char e;
int main(){
	freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=4;i++){
    	for(int j=1;j<=4;j++){
    		a[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
    	cin>>x>>y>>z>>e;
    	a[x][y]=z;
		}
    cout<<"Game over!";
	//for(int i=1;i<=4;i++){
		//for(int j=1;j<=4;j++){
			//if(j==4)cout<<a[i][j]<<endl;
			//else cout<<a[i][j]<<" ";
		//}
	//}
	return 0;
} 
