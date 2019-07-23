#include <bits/stdc++.h>
using namespace std;
int wo(int a,int b,int c,int d){
	return (a*b+c)%d; 
}
int has1[1000010],has2[1000010];
int main(){
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	int x1,m,t,h1,a1,x2,y2,y1,h2,a2;
	int f1=0,f2=0;
	int xh1,xh2;
	scanf("%d",&t);
	for(int z=0;z<t;z++){
		bool flag=true;
		scanf("%d%d%d%d%d%d%d%d%d",&m,&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
		has1[0]=h1;
		has2[0]=h2;
		for(int i=1;;i++){
			if(has1[wo(x1,has1[i-1],y1,m)]==0){
				has1[wo(x1,has1[i-1],y1,m)]=i;
			}else{
				xh1=i-has1[wo(x1,has1[i-1],y1,m)];
				if(f1==0){
					printf("-1\n");
					flag=false;
					break;
				}else{
					f1=has1[a1];
					break;
				}
			}
		}
		if(flag){
			for(int i=1;;i++){
				if(has2[wo(x2,has2[i-1],y2,m)]==0){
					has2[wo(x2,has2[i-1],y2,m)]=i;
				}else{
					xh2=i-has2[wo(x2,has2[i-1],y2,m)];
					if(f2==0){
						printf("-1\n");
						flag=false;
						break;
					}else{
						f2=has2[a2];
						break;
					}
				}
			}
		}
		if(flag){
			if(f1!=f2&&xh1==xh2){
				printf("-1\n"); 
				flag=false;
			}
		}
		if(flag){
			if(f1==f2){
				printf("%d\n",has1[a1]);
			}else{
				
				
				
			}
		}
		
	}
	return 0;
}
