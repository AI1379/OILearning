#include<bits/stdc++.h>
using namespace std;
const int MAXL=1000000;
int fish[MAXL],cnt;
int main(){
	int n,i,j,k,ans=0;
	vector<int>f[3];
	cin>>n;
	f[0].resize(n+1);
	f[1].resize(n+1);
	f[2].resize(n+1);
	for(i=0;i<n;i++) cin>>fish[i];
	for(i=0;i<n;i++) f[1][i]=0;
	for(k=2;k<=n;k++){
		for(i=0;i<n-k+1;i++){
			cnt=0;
			for(j=i;j<i+k-1;j++){
				if(fish[j]>fish[i+k-1])
					cnt++;
			}
			f[2][i]=f[1][i]+cnt;
			ans+=f[2][i];
		}
		for(i=0;i<n;i++) f[1][i]=f[2][i];
	}
//	for(i=1;i<=n;i++){
//		for(j=0;j<n;j++){
//			ans+=f[i][j];
//			cout<<f[i][j]<<' ';
//		} 
//		cout<<endl;
//	} 
	cout<<ans;
	system("pause");
	return 0;
}