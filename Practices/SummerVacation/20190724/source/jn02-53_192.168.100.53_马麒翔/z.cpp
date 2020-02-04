#include<bits/stdc++.h>
using namespace std;
int c[501],w[501],f[50001],num[501];
int cc[501],ww[501],ff[50001],nn[501];
int n,p,mey,m,l=0,r,mid;
int ans;
bool check(int v) {
//	memset(f,-0x3f,sizeof(f));
//	f[0]=0;
	for(int i=1; i<=n; i++)
		for(int j=v;j>=0;j--) {
			for(int k=0; k<=num[i]; k++) {
				if(w[i]*k<=j) f[j]=max(f[j],f[j-w[i]*k]+c[i]*k);
				else {
					break;
				}
			}
		}
//	cout<<"***"<<f[v]<<endl;
	if(f[v]>=p) return true;
	else return false;
}
bool checkk(int u) {
//	memset(f,-0x3f,sizeof(f));
//	f[0]=0;
	for(int i=1; i<=n; i++)
		for(int j=u;j>=0;j--) {
			for(int k=0; k<=nn[i]; k++) {
				if(ww[i]*k<=j) ff[j]=max(ff[j],ff[j-ww[i]*k]+cc[i]*k);
				else {
					break;
				}
			}
		}
//	cout<<"***"<<ff[u]<<endl;
	if(ff[u]>=ans) return true;
	else return false;
}
int main() {
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	cin>>n>>m;
	cin>>p>>mey;
	for(int i=1; i<=n; i++) {
		cin>>c[i]>>w[i]>>num[i];
		r+=w[i]*num[i];
	}
//	cout<<l<<" "<<r<<endl;
	while(l<=r) {
		mid=(l+r)/2;
		if(check(mid)) {
			ans=mid;
			r=mid-1;
		} else l=mid+1;
//		cout<<mid<<endl;
	}
	cout<<ans<<endl;
	//PART ONE
	
	
	
	
	r=0;l=0;
	for(int i=1;i<=m;i++)
	{
		cin>>cc[i]>>ww[i]>>nn[i];
		r+=ww[i]*nn[i];
	}
	int aans;
//	cout<<l<<" "<<r<<endl;
	while(l<=r) {
		mid=(l+r)/2;
		if(checkk(mid)) {
			aans=mid;
			r=mid-1;
		} else l=mid+1;
//		cout<<mid<<endl;
	}
	if(aans<=mey)
	cout<<aans<<endl;
	else cout<<"FAIL"<<endl;
	//PART TWO
	
	
	
	return 0;
}
