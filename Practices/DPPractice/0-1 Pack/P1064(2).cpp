#include <bits/stdc++.h>
#define DEBUG true
using namespace std;
const int maxn=32010;
const int maxm=4900;
int f[maxm][maxn],w[maxn],c[maxn],tmpw[maxm],tmpc[maxm],ai[maxm],n,m,tmpm,tmpk,times;
bool vis[maxm][maxm];
int main(){
	int i,j,k,p,q,r,x,y,z;
	cin>>n>>m;
	tmpm=m;
	freopen("out.txt","w",stdout);
	memset(ai,0,sizeof(ai));
	memset(vis,0,sizeof(vis));
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
				vis[j][q]=true;
				vis[q][j]=true;
			}
			else{
				w[j]=tmpw[q]+tmpw[i];
				c[j]=tmpc[q]+tmpc[i];
				vis[q][j]=true;
				vis[j][q]=true;
				vis[j][ai[q]]=true;
				vis[ai[q]][j]=true;
				j++;
				w[j]=w[ai[q]]+tmpw[i];
				c[j]=c[ai[q]]+tmpc[i];
				vis[q][j]=true;
				vis[j][q]=true;
				vis[q][j-1]=true;
				vis[j-1][q]=true;
				vis[j][j-1]=true;
				vis[j-1][j]=true;
				vis[j][ai[q]]=true;
				vis[ai[q]][j]=true;
				tmpm++;
			}
		}
	}
	#if DEBUG
	cout<<"C:";
	for(i=0;i<=tmpm;i++)cout<<c[i]<<' ';
	cout<<"\nW:";
	for(i=0;i<=tmpm;i++)cout<<w[i]<<' ';
	cout<<"\nOC:";
	for(i=0;i<=m;i++)cout<<tmpc[i]<<' ';
	cout<<"\nOW:";
	for(i=0;i<=m;i++)cout<<tmpw[i]<<' ';
	cout<<endl;
	#endif
	m=tmpm;
	for(i=1;i<=m;i++){
		for(j=c[i];j<=n;j++){
			times=0;
			for(k=1;k<i;k++){
				if(vis[i][k]){
					times++;
					if(times==1){
						tmpk=k;
						x=f[i-1][j-c[k]]+w[k];//选k(不选i)
						y=f[i-1][j+c[k]-c[i]]+w[i]-w[k];//选i
						z=f[i-2][j+c[k]]-w[k];//啥都不选
						f[i][j]=max(x,max(y,z));
					}
					else{
						//i,k,tmpk,k+1
						x=f[i-3][j+c[tmpk]+c[k]+c[k+1]-c[i]]+w[i]-w[k+1]-w[k]-w[tmpk];//选i
						y=f[i-3][j+c[tmpk]+c[k+1]-c[k]]-w[tmpk]-w[k+1]+w[k];//选k
						z=f[i-3][j+c[k]+c[k+1]-c[tmpk]]-w[k]-w[k+1]+w[tmpk];//选tmpk
						p=f[i-3][j+c[tmpk]+c[k]-c[k+1]]-w[tmpk]-w[k]+w[k+1];//k+1
						q=f[i-4][j+c[tmpk]+c[k]+c[k+1]]-w[k]-w[tmpk]-w[k+1];//none
						f[i][j]=max(x,max(y,max(z,max(p,q))));
						break;
					}
				}
			}
			if(times==0)
				f[i][j]=max(f[i-1][j],f[i-1][j-c[i]]+w[i]);
//			else if(times==1){
//				f[i][j]=max(f[i-1][j+c[tmpk]-c[i]]-w[tmpk]+w[i],max(f[i-1][j],f[i-2][j+c[tmpk]]-w[tmpk]));
//			}
//			else{
//				可选: i,k,tmpk,k+1,none
//				f[i][j]=max(f[i-4][j+c[k]+c[tmpk]+c[k+1]],max(f[i-3][j+c[k]+c[tmpk]+c[k+1]-c[i]]-w[k]-w[tmpk]-w[k+1]+w[i],max(f[i-3][j+c[tmpk]+c[k+1]-c[k]]-w[tmpk]-w[k+1]+w[k],max(f[i-3][j+c[k]+c[k+1]-c[tmpk]]-w[k]-w[k+1]+w[tmpk],f[i-3][j+c[tmpk]+c[k]-c[k+1]]-w[tmpk]-w[k]+w[k+1]))));
//			}
			#if DEBUG
			cout<<f[i][j]<<' ';
			#endif
		}
		#if DEBUG
		cout<<endl;
		#endif
	}
	fclose(stdout);
	freopen("CON","w",stdout);
	cout<<f[m][n];
	return 0;
}
