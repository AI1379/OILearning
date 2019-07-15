#include<bits/stdc++.h>
using namespace std;
const int MAXL=1000000;
unsigned long long fish[MAXL],cnt;
int main(){
	unsigned long long n,i,j,k,ans=0;
	vector<unsigned long long>f[2];
	cin>>n;
	f[0].resize(n+1);
	f[1].resize(n+1);
	for(i=0;i<n;i++) cin>>fish[i];
	for(i=0;i<n;i++) f[0][i]=0;
	for(k=2;k<=n;k++){
		for(i=0;i<n-k+1;i++){
			cnt=0;
			for(j=i;j<i+k-1;j++){
				if(fish[j]>fish[i+k-1])
					cnt++;
			}
			f[(k+1)%2][i]=f[k%2][i]+cnt;
			ans+=f[(k+1)%2][i];
		}
	}
	cout<<ans;
	system("pause");
	return 0;
}