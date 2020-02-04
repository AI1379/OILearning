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
int a,b,c;
int t;
/*inline bool judge(int x){
	int aa=a-x,bb=b-x;
	int ans=-1,l=0,r=bb;
	if(aa<0||bb<0)return 0;
	for(int i=0;i<=aa/2;i++){
		int ax=i,xx=x,bx=min(aa-i*2,bb/2);
		int mi=min(ax,min(bx,xx));
		ax-=mi;bx-=mi;xx-=mi;
		if(ax&&bx){
			if()
		}
	}
}*/
int main(){
	freopen("store.in","r",stdin);
	freopen("store.out","w",stdout);
	read(t);
	while(t--){
		read(a),read(b),read(c);
		int mi=min(a,b);
		mi=min(mi,(int)((a+b+c)/3));
		writeln(mi);
	}
	return 0;
}
