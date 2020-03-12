#include <bits/stdc++.h>
using namespace std;
int mapp[600][600],eans1=0,eans2=0;
int ans1[600],ans2[600];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int h,w,m;
	scanf("%d%d%d",&h,&w,&m);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			scanf("%d",&mapp[i][j]);
		}
	}
	for(int i=0;i<h;i++){
		for(int j=1;j<w;j++){
			if(abs(mapp[i][j]-mapp[i][j-1])>m){
				ans1[i]++;
			}
		} 
		eans1+=ans1[i];
	}
	for(int i=0;i<h;i++){
		for(int j=1;j<w;j++){
			if(abs(mapp[j][i]-mapp[j][i-1])>m){
				ans2[i]++;
			}
		} 
		eans2+=ans2[i];
	}
	printf("%d %d\n",eans1,eans2);
	if(eans1-eans2+h<eans1&&eans1-eans2+h<eans2){
		printf("%d",eans2-eans1+w);
	}else if(eans2-eans1+w<eans1&&eans2-eans1+w<eans2){
		printf("%d",eans1-eans2+h);
	}
	else
	printf("%d",min(eans2-eans1+w,eans1-eans2+h);
	return 0;
}
