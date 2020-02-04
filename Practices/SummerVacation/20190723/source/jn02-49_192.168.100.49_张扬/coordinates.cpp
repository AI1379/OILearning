#include <bits/stdc++.h>
using namespace std;
struct fjj{
	int x;
	int y;
}wz[250];
bool cmp(fjj a,fjj b){
	if(a.y!=b.y){
		return a.y>b.y;
	}else{
		return a.x<b.x;
	}
}
int gs,minx=0,maxx=0,miny=0,maxy=0;
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
	scanf("%d",&gs);
	int ls=0;
	for(int i=0;i<gs;i++){
		scanf("%d%d",&wz[i].x,&wz[i].y);
		if(wz[i].x>maxx){
			maxx=wz[i].x;
		}
		if(wz[i].x<minx){
			minx=wz[i].x;
		}
	}
	sort(wz,wz+gs,cmp);
	maxy=wz[0].y;
	miny=wz[gs-1].y;
	for(int i=maxy;i>=min(0,miny);i--){
		for(int j=min(0,minx);j<=maxx;j++){
			if(i==wz[ls].y&&j==wz[ls].x){
				ls++;
				printf("*");
				continue;
			}else{
				if(i==0&&j==0){
					printf("+");
				}else if(i==0&&j!=0){
					printf("-");
				}else if(j==0&&i!=0){
					printf("|");
				}else{
					printf(".");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
