#include<bits/stdc++.h>
using namespace std;
struct kk{
	int num,shu;
}a[5001];
int n,f[1001];
const int INF=1<<30;
int main(){
	freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].shu,a[i].num=i,f[i]=INF/3;
	int t=a[1].shu,k1=-1,p=1,k2;
	f[1]=0;
	for(int i=2;i<=n;i++){
		if(i<t+1){
			f[i]=min(f[i],p);
			if(k1<a[i].shu){
				k1=a[i].shu;
				k2=a[i].num;
			}
		}
		else{
			f[i]=min(f[i],p);
			if(k1<a[i].shu){
				k1=a[i].shu;
				k2=a[i].num;
			}
			t=t+k1-(i-k2);
			p++;
			k1=-1;
		}
	}
	cout<<f[n];
	return 0;
}
