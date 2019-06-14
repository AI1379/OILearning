#include <bits/stdc++.h>
using namespace std;
const int maxn=32010;
const int maxm=4900;
int f[maxn],w[maxn],c[maxn],tmpw[maxm],tmpc[maxm],ai[maxm],n,m,tmpm;
int main(){
	int i,j,p,q;
	cin>>n>>m;
	tmpm=m;
	memset(ai,0,sizeof(ai));
	for(i=1,j=1;i<=m;i++,j++){
		cin>>tmpc[i]>>p>>q;
		tmpw[i]=tmpc[i]*p;
		if(q==0){
			w[j]=tmpw[i];
			c[j]=tmpc[i];
		}
		else{
			if(ai[q]==0){
				ai[q]=j;
				w[j]=tmpw[q]+tmpw[i];
				c[j]=tmpc[q]+tmpc[i];
			}
			else{
				w[j]=tmpw[q]+tmpw[i];
				c[j]=tmpc[q]+tmpc[i];
				j++;
				w[j]=w[ai[q]]+tmpw[i];
				c[j]=c[ai[q]]+tmpc[i];
				tmpm++;
			}
		}
	}
	m=tmpm;
	for(i=1;i<=m;i++){
		for(j=n;j>=c[i];j--){
			f[j]=max(f[j],f[j-c[i]]+w[i]);
		}
	}
	cout<<f[n];
	return 0;
}
