#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,n,i,ans=0;
	bool appeared[100001];
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>n;
	memset(appeared,false,sizeof(appeared));
	for(i=0;i<n;i++){
		cin>>x>>y;
		if(x+y+1!=n)
			ans++;
		else if(appeared[x])
			ans++;
		else appeared[x]=true;
	}
	cout<<ans;
	return 0;
}
