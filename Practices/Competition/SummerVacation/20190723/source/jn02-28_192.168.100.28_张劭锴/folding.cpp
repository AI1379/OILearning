#include<bits/stdc++.h>
using namespace std;
int ans=0;
void zhe(int x,int y){
	while(x>y){
		x=x-x/2;
		ans++;
	}
}
int main(){
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	int a,b,c,d,t;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a<b)	t=a,a=b,b=t;
	if(c<d) t=c,c=d,d=t;
	if(a<c||a<=d||b<d){
		printf("-1");
		return 0;
	}
	zhe(a,c);
	zhe(b,d);
	printf("%d",ans);
	return 0;
}
