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
int p(int x,int y){
	if(y==0&&x!=0)
		return 1;
	int a=x,b=y,ans=0;
	while(b>0){
		if(b%2==0)
			ans=ans*a;
		a=a*a;
		b/=2;
	}
	return ans;
}
int main(){
	int n,i,k=0,ans=0,cnt,a;
	cin>>n;
	cnt=ws(n);
	a=0;
	for(i=1;i<cnt;i++){
		a=a+i*(9*p(10,i-1)-1);
		k=k+9*p(10,i-1);
	}
	a++;
	ans=a+cnt*(n-k);
	cout<<ans;
	return 0;
}
