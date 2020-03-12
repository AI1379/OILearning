//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<iostream>
//#include<>
using namespace std;
inline int read(){
	register int x;register char c(getchar());register bool k;
	//while((c<'0'||c>'9')&&c^'-')if((c=getchar())==EOF)exit(0);
	if(c^'-')x=c-'0',k=1;else x=0,k=0;
	for(c=getchar();c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+c-'0';
	return k?x:((~x)+1);
}
int main(){
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	int W,H,w,h,ans=-1;
	scanf("%d%d%d%d",&W,&H,&w,&h);
	/*if((H<h&&W<h)||(H<w&&W<w)||(H<h&&H<w)||(W<h&&W<w)){
		printf("-1");
		return 0;
	}
	{
		cout<<min(((ceil(log((double)W/w)))+(ceil(log((double)H/h)))),((ceil(log((double)W/h)))+(ceil(log((double)H/w)))))<<endl;
		cout<<((ceil(log((double)W/h)))+(ceil(log((double)H/w))))<<endl;
		cout<<((ceil(log((double)W/w)))+(ceil(log((double)H/h))))<<endl;
		cout<<(ceil(log((double)W/w)))<<endl;
		cout<<(ceil(log((double)H/h)))<<endl;
		cout<<(ceil(log((double)W/h)))<<endl;
		cout<<(ceil(log((double)H/w)))<<endl;
	}*/
	if(H>=h&&W>=w)ans=max(ans,(int)((ceil(log((double)W/w)))+(ceil(log((double)H/h)))));
	if(H>=w&&W>=h)ans=max(ans,(int)((ceil(log((double)W/h)))+(ceil(log((double)H/w)))));
	printf("%d",ans);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
