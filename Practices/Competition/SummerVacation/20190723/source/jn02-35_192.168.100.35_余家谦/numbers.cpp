#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("numbers.in","r",stdin);
	freopen("numbers.out","w",stdout);
	int n,a,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		cout<<(a-b)*2<<endl;
	}
	return 0;
}
