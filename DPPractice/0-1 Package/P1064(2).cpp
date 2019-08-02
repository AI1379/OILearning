#include <bits/stdc++.h>
using namespace std;
const int maxn=32010;
const int maxm=4900;
int f[maxm][maxn],w[maxn],c[maxn],tmpw[maxm],tmpc[maxm],ai[maxm],n,m,tmpm;
bool vis[maxm][maxm];
int main(){
	int i,j,k,p,q,tmp,tmp2;
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
				vis[q][j]=true;
				vis[j][q]=true;
			}
			else{
				w[j]=tmpw[q]+tmpw[i];
				c[j]=tmpc[q]+tmpc[i];
				j++;
				w[j]=w[ai[q]]+tmpw[i];
				c[j]=c[ai[q]]+tmpc[i];
				tmpm++;
				vis[q][j]=true;
				vis[j][q]=true;
				vis[q][j-1]=true;
				vis[j-1][q]=true;
				vis[ai[q]][j]=true;
				vis[j][ai[q]]=true;
			}
		}
	}
	m=tmpm;
	for(i=1;i<=m;i++){
		for(j=n;j>=c[i];j--){
			tmp=0;
			tmp2=0;
			for(k=0;k<i;k++){
				if(vis[k][i]){
					tmp2+=w[k];
					tmp+=c[k];
					f[i][j]=max(f[i-1][j],f[i-1][j+tmp]-tmp2+w[i]);
				}
				else{
					f[i][j]=max(f[i-1][j],f[i-1][j-c[i]]+w[i]);
				}
			}
		}
	}
	cout<<f[m][n];
	system("pause");
	return 0;
}
