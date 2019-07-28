#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,c[100001],i,ans=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>c[i];
		ans+=c[i];
	}
	sort(c,c+n,cmp);
	for(i=3;i<n;i+=3)
		ans-=c[i];
	cout<<ans;
	return 0;
}
