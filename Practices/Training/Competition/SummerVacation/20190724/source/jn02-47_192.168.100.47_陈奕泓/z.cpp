#include<bits/stdc++.h>
using namespace std;
int v[500],w[500],s[500];
int f[500];
int n,m,a,b;
int main(){
	freopen("z.in","r",stdin);
	freopen("z.out","w",stdout);
	scanf("%d%d%d%d",&n,&a,&b,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&w[i],&v[i],&s[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){
			for(int k=0;k<=s[i];k++){
				if(j-k*v[i]<0)
					break;
				f[j]=max(f[j],f[j-k*v[i]+k*w[i]]);
			}
		}
	}
	printf("%d\n",f[m]);
	for(int i=1;i<=a;i++){
		scanf("%d%d%d",&w[i],&v[i],&s[i]);
	}
	printf("FAIL\n");
	return 0;
}
