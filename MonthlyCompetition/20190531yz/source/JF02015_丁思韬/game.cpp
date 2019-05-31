#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int n=4;
int q,ma[10][10],st[200];
bool full(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(!ma[i][j])
				return 0;
	return 1;
}
void work(){
	int i,j,k,num,a[10];
	for(i=1;i<=n;i++){
		memset(a,0,sizeof(a));
		num=0;
		for(j=1;j<=n;j++)
			if(ma[i][j])
				a[++num]=ma[i][j];
		for(j=1;a[j];j++)
			if(a[j]==a[j+1]){
				a[j]<<=1,a[j+1]=0;
				for(k=j+1;a[k];k++)
					a[k]=a[k+1];
			}	
		for(j=1;j<=n;j++)
			ma[i][j]=a[j];
	}
}
void turn(){//Ë³Ê±Õë
	int t[10][10]={0},i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			t[i][j]=ma[n-j+1][i];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			ma[i][j]=t[i][j];
}
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",ma[i][j]);
		printf("\n");
	}
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	st['L']=0;st['D']=1;st['R']=2;st['U']=3;
	int i,j,x,y,v;
	char opt;
	cin>>q;
	while(q--){//1000
		cin>>x>>y>>v>>opt;
		ma[x][y]=v;
		for(i=1;i<=st[opt];i++)//4
			turn();//16
		work();//64
		for(i=1;i<=n-st[opt];i++)//4
			turn();//16
		if(full()){//16
			printf("Game over!");
			return 0;
		}
	}
	print();
	return 0;
} 
