#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,a[3],i;
	freopen("ljc.in","r",stdin);
	freopen("ljc.out","w",stdout);
	cin>>T;
	for(i=0;i<T;i++){
		cin>>a[0]>>a[1]>>a[2];
		if(a[0]==a[1]&&a[1]==a[2]){
			cout<<'J'<<endl;
			continue;
		}
		sort(a,a+3);
		if(a[2]-a[1]==1&&a[1]-a[0]==1){
			cout<<'L'<<endl;
			continue;
		}
		cout<<'C'<<endl;
	}
	return 0;
}
