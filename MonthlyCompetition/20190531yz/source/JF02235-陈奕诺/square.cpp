#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T> inline void read(T&x) {
    char ch=getchar();
    x=0;
    bool f=0;
    for(; ch<'0'||ch>'9'; ch=getchar())if(ch=='-')f=1;
    for(; ch>='0'&&ch<='9'; x=(x<<1)+(x<<3)+(ch&15),ch=getchar());
    if(f)x=-x;
}
template<typename T> inline void write(T x) {
    if(x<0)x=-x,putchar('-');
    if(x>9)write(x/10);
    putchar(x%10|48);
}
template<typename T> inline void writeln(T x) {
    write(x),putchar('\n');
}
double a[10];
int n,k;
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	read(n),read(k);
	double l=n;
	int cnt=0;
	for(int i=1;i<=k;i++){
		double x=l;
		for(int i=1;i<=4;i++){
			cnt++;
			a[cnt%3]+=x;
		}
		l=sqrt(l*l/2);
	}
	printf("%.3lf %.3lf %.3lf\n",a[1],a[2],a[0]);
	return 0;
}
