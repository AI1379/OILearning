#include<bits/stdc++.h>
using namespace std;
const int maxn=32010;
const int maxm=70;
int f[maxn],w[maxn],c[maxn],tmpw[maxm],tmpc[maxm],ai[maxm],n,m;
bool annex[maxm];
int main(){
	int i,j,v,p,q;
	cin>>n>>m;
	memset(annex,false,sizeof(annex));
	for(i=1,j=1;i<=m;i++,j++){
		cin>>v>>p>>q;
		if(q!=0){
			if(!annex[q]){
				w[j]=tmpw[q]+v*p;
				c[j]=tmpc[q]+v;
				tmpw[i]=v*p;
				tmpc[i]=v;
				ai[q]=i;
				annex[q]=true;
			}
			else{
				w[j]=tmpw[q]+v*p;
				c[j]=tmpc[q]+v;
				j++;
				w[j]=tmpw[q]+tmpw[ai[q]]+v*p;
				c[j]=tmpc[q]+tmpc[ai[q]]+v;
				n++;
			}
		}
		else{
			tmpw[i]=v*p;
			tmpc[i]=v;
			w[j]=v*p;
			c[j]=v;
		}
	}
	for(i=1;i<=m;i++){
		for(j=n;j>=c[i];j--){
			f[j]=max(f[j],f[j-c[i]]+w[i]);
		}
	}
	cout<<f[n];
	return 0;
}
