#include<bits/stdc++.h>
using namespace std;
const int MAXL=1000000;
int fish[MAXL],cnt;
int main(){
	int n,i,j,k,ans=0;
	int f[1000][1000];
	cin>>n;
	memset(f,0,sizeof(f));
	for(i=0;i<n;i++) cin>>fish[i];
	for(i=0;i<n-1;i++)
		if(fish[i]>fish[i+1])
			f[i][i+1]=1;
	for(k=3;k<=n;k++){
		for(i=0;i<n-k;i++){
			cnt=0;
			for(j=1;j<k;j++){
				if(fish[i]<fish[i+j])
					cnt++;
			}
			f[i][i+k-1]=f[i+1][i+k-1]+cnt;
		}
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			ans+=f[i][j];
	cout<<ans;
	system("pause");
	return 0;
}