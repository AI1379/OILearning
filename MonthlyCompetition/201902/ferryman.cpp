#include<cstdio>
using namespace std;
int x,y,k,t,a[20000001];
long long ans;
int main(){
	freopen("ferryman.in","r",stdin);
	freopen("ferryman.out","w",stdout);
	scanf("%d%d%d%d%d",&a[1],&x,&y,&k,&t);
	for(int i=1;i<=t;i++){
		ans+=a[i];
		a[i+x]+=a[i]/k;
		a[i+y]+=a[i]-a[i]/k;
	}
	printf("%lld\n",ans);
	return 0;
}
