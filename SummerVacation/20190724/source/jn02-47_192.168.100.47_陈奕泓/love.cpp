#include<bits/stdc++.h>
using namespace std;
long long m=63;
long long z=1,w,a[4000];
long long e[100];
int t,l,r,xl,y;
void x(){
	e[1]=1;
	for(int i=2;i<m;i++){
		e[i]=2*e[i-1];
	}
}
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	x();
	for(int i=2;i<m;i++){
		for(int j=i-1;j>0;j--){
			a[z]=e[i+1]-e[j]-1;
			z++;
		}
	}
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d%d",&l,&r);
		bool f=false;
		for(int j=1;j<z;j++){
			if(a[j]>=l&&f==false){
				xl=j;
				f=true;
			}
			if(a[j]>r){
				y=j;
				break;
			}
		}
		printf("%d\n",y-xl);
	}
	return 0;
}
