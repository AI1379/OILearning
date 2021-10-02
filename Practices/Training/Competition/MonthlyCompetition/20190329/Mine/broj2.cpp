#include<bits/stdc++.h>
using namespace std;
int ws(int a){
	int x=a,cnt=0;
	while(x!=0){
		x/=10;
		cnt++;
	}
	return cnt;
}
int main(){
	int n,i,ans=0;
	cin>>n;
	for(i=1;i<=n;i++)
		ans=ans+ws(i);
	cout<<ans;
	return 0;
}
