#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define For(i,j,k) for (int i=(j);i<=(k);++i)
#define foR(i,j,k) for (int i=(j);i>=(k);--i)
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
const int N=100100;
int ran(){return (rand()<<16)+rand();}
int f[N],a[N],n;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	read(n);
	For (i,1,n) read(a[i]);
	For (i,2,n){
		f[i]=0x7fffffff;
		For (j,1,i-1)
			if (j+a[j]>=i)
				cmin(f[i],f[j]+1);
	}
	cout<<f[n]<<endl;
	return 0;
}
