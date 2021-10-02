//Coded by dst
#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
struct Res{
	int s,r;//s:the time to a, r:the time of one round
};
int T,m,h1,a1,x1,y1,h2,a2,x2,y2,cnt[1000005];
bool flag;
Res res1,res2;
Res calc(int h,int a,int x,int y){
	if(h==a)
		return (Res){0,0};
	memset(cnt,0,sizeof(cnt));
	Res res;
	res.s=res.r=0;
	int u,v;
	for(u=h,v=(u*x+y)%m;!cnt[v];u=v,v=(u*x+y)%m){
		cnt[v]=cnt[u]+1;
		if(v==a)
			res.s=cnt[v];
	}
	if(!res.s){//-1 
		flag=1;
		return res;
	}
	res.r=cnt[u]-cnt[v]+1;
	if(cnt[a]<cnt[v])//a在链上 
		res.r=-1;
	return res;
}
void solve1(int x,int y){
	if(x!=y)
		printf("-1\n");
	else
		printf("%lld\n",x);
}
void solve2(int a,int b,int c){//a=b+cx -> cx=a-b
	if(a<b||(a-b)%c!=0)
		printf("-1\n");
	else
		printf("%lld\n",a);
}
int exgcd(int m,int &x,int n,int &y){
    int x1,y1,x0,y0;
    x0=1;y0=0;
    x1=0;y1=1;
    int r=(m%n+n)%n;
    int q=(m-r)/n;
    x=0;y=1;
    while(r){
        x=x0-q*x1;
        y=y0-q*y1;
        x0=x1;
        y0=y1;
        x1=x;y1=y;
        m=n;n=r;r=m%n;
        q=(m-r)/n;
    }
    return n;
}
int solve3(int a,int b,int c){//ax+by=c最小整数解 return x
	int x,y,M=exgcd(a,x,b,y);
    if(c%M!=0)
        return -1;
    else{
        x=x*c/M;
        return (x%(b/M)+b/M)%(b/M);
    }
}
signed main(){
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	int res;
	scanf("%lld",&T);
	while(T--){
		flag=0;
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&m,&h1,&a1,&x1,&y1,&h2,&a2,&x2,&y2);
		res1=calc(h1,a1,x1,y1);
		res2=calc(h2,a2,x2,y2);
		//r1*x+s1=r2*y+s2=ans
		//r1*x-r2*y=s2-s1
		if(flag)
			printf("-1\n");
		else{ 
			if(res2.r==-1)
				swap(res1,res2);
			if(res1.r==-1&&res2.r==-1)//两点都在链上 
				solve1(res1.s,res2.s);
			else if(res1.r==-1)//一点在链上 
				solve2(res1.s,res2.s,res2.r);
			else{//两点都在环内 
				res=solve3(res1.r,-res2.r,res2.s-res1.s);
				if(res==-1)
					printf("-1\n");
				else
					printf("%lld\n",res1.r*res+res1.s);
			}
		} 
	}
	return 0;
}
