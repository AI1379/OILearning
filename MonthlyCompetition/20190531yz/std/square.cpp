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
double a[3],n;
int k;
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	read(n),read(k);
	For (i,1,4*k){
		a[i%3]+=n;
		if (i%4==0)
			n=n*sqrt(2)/2;
	}
	printf("%.3f %.3f %.3f\n",a[1],a[2],a[0]);
	return 0;
}

