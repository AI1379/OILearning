#include<bits/stdc++.h>
using namespace std;
int p(int x,int y,int p){
    int ans=1,a=x,b=y;
    while(b>0){
    	if(b%2==1)
    		ans=ans*a%p;
    	a=a*a%p;
    	b/=2;
	}
	return ans;
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<(n*p(2,n,k)+1)%k;
    //cout<<(p(n,n,k)-n%k+1)%k;
    return 0;
}
