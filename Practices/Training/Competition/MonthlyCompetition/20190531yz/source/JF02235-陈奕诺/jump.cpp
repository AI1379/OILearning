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
#define N 5005
int n,a[N],f[N],mx;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),f[i+1]=1e9;
	f[1]=0;
	mx=a[1];
	for(int i=2;i<=n;i++){
		int R=max(i-mx,1);
		for(int j=i-1;j>=R;j--){
			if(a[j]+j>=i){
				f[i]=min(f[i],f[j]+1);
			}
		}
		mx=max(mx,a[i]);
	}
	cout<<f[n];
	return 0;
}
