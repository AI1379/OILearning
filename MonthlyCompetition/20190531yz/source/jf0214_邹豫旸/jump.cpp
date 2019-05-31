#include<bits/stdc++.h>
using namespace std;
int n,a[5005],f[5005],now1,now2,maxx;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	f[1]=0;
	now1=a[1]+1;
	now2=0;
	maxx=a[1]+1;
	for(int i=2; i<=n; i++){
		if(i<=now1) f[i]=now2+1,maxx=max(i+a[i],maxx);
		else{
			now1=maxx,now2++;
			if(i<=now1) f[i]=now2+1,maxx=max(i+a[i],maxx);
		} 
	}
	cout<<f[n];
	return 0;
}
