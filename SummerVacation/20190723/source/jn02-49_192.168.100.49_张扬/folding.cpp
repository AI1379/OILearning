#include <bits/stdc++.h>
using namespace std;
int cl(double a){
	for(int i=0;;i++){
		if(pow(2,i)>=a){
			return i;
		}
	}
}
int W,H,w,h;
int main(){
	double c,d,e,f;
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	scanf("%d%d%d%d",&W,&H,&w,&h);
	if(W<H){
		int ls=W;
		W=H;
		H=ls;
	}
	if(w<h){
		int ls=w;
		w=h;
		h=ls;
	}
	c=1.0*W/w;
	d=1.0*H/h;
	e=1.0*W/h;
	f=1.0*H/w;
	if(W<w||H<h){
		printf("-1");
	}else{
		printf("%d",min((cl(c)+cl(d)),(cl(e)+cl(f))));
	}
	return 0;
}
