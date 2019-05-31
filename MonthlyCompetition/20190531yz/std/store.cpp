#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define For(i,j,k) for (int i=j;i<=k;++i)
#define foR(i,j,k) for (int i=j;i>=k;--i)
#define mem(a,x) memset(a,x,sizeof(a))
#define sqr(x) (x)*(x)
template <typename T>void cmin(T &a,T b){a=min(a,b);}
template <typename T>void cmax(T &a,T b){a=max(a,b);}
template <typename T>
void read(T &x){
	char c;T f=1;
	while (!isdigit(c=getchar())) if (c=='-') f=-1;
	x=c-'0';
	while (isdigit(c=getchar())) x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	int T;
	read(T);
	For (i,1,T){
		int a,b,c;read(a),read(b),read(c);
		int l=0,r=0x7fffffff;
		while (l+1<r){
			int mid=(l+r)>>1,A=a-mid,B=b-mid,C=c;
			if (A>=0&&B>=0&&A+B+C>=mid&&(A+B)>=mid>>1&&(B+C)>=mid>>1&&(A+C)>=mid>>1)
				l=mid;
				else r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}

