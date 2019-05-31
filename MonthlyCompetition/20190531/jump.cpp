#include<bits/stdc++.h>
using namespace std;
const int INFINTY=1<<30;
int a[5010],f[5010];
int n;
int main(){
	int i,j;
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=2;i<=n;i++){
		f[i]=INFINTY;
		for(j=1;j<=i;j++){
			if(a[j]+j>=i)
				f[i]=min(f[i],f[j]+1);
		}
	}
	cout<<f[n];
	return 0;
} 
