#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000],n;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	b[0]=0;
	for(int i=1;i<n;i++){
		b[i]=100000;
		for(int j=0;j<i;j++){
			if(j+a[j]>=i){
				b[i]=min(b[i],b[j]+1);
			}
		}
	}
	printf("%d\n",b[n-1]);
	return 0;
}
