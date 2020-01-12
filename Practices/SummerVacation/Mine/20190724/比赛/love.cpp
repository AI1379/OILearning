#include<bits/stdc++.h>
using namespace std;
int main(){
	long long l,r,t,i,k,x,ans,num;
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	cin>>t;
	for(k=0;k<t;k++){
		cin>>l>>r;
		ans=0;
		for(i=l;i<=r;i++){
			num=0;
			x=i;
			while(x>0){
				if(x%2==0)
					num++;
				x=x>>1;
			}
			if(num==1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
