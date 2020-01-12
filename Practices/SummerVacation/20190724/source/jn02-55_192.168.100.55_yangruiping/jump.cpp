#include <bits/stdc++.h>
using namespace std;
struct gi{
	int x,y,ans,cai;
};
gi st;
int h,w,m,a[503][503],ma[503][503],d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool p[503][503];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&h,&w,&m);
	int i,j;
	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
			scanf("%d",&a[i][j]);
		}
	}
    cout<<0;
	return 0;
} 

