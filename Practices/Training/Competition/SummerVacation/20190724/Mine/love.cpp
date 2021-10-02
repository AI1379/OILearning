#include<bits/stdc++.h>
using namespace std;
long long lg2(long long n){
	int x=n,ans=0;
	while(x>0){
		x=x>>1;
		ans++;
	}
	return ans;
}
long long non(long long n){
	if(n<2)return 0;
	else if(n==2||n==3)return 1;
	long long x=lg2(n),ans,i,k;
	ans=(x-2)*(x-3)/2;
	i=1<<(x-3);
	k=(1<<x)-(1<<(x-2))-1;
	while(k<=n){
		ans++;
		i=i>>1;
		k+=i;
	}
	return ans;
}
int main(){
	long long l,r,t,i,k,x,ans,num,n;
	cin>>t;
	for(k=0;k<t;k++){
		cin>>l>>r;
		cout<<(non(r)-non(l-1))<<endl;
	}
	system("pause");
	return 0;
}
