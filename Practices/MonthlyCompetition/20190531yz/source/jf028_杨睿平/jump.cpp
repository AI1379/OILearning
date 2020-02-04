#include <bits/stdc++.h>
using namespace std;
const int INF=1e9;
int n;
int a[50005],f[50005];
void dp(){
	int i,j,k,minn;
	bool p;
	f[n]=0;
	for(i=n-1;i>0;i--){
		p=false;
		minn=INF+1;
		for(j=1;j<=a[i];j++){
			k=i+j;
			if(i+j>=n){
				p=true;
				break;
			}	
			if(f[k]<minn){
				minn=f[k];
			}
		}
		if(p){
			f[i]=f[n]+1;
		}else{
			f[i]=minn+1;
		}
	}
}
int main(){
	freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);	
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++){
    	scanf("%d",&a[i]);
	}
	for(i=1;i<n;i++){
		f[i]=INF/2;
	}
	dp();
	cout<<f[1];
	return 0;
}
