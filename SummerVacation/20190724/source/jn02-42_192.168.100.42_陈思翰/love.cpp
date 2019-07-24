#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	long long t,l,r,i,w,q,s,p,o,ans=0,j,k;
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>l>>r;
		ans=0;
		w=l;
		q=0;
		p=1;
		o=1;
		while(w!=0){
			w/=2;
			q++;
			p*=2;
		}
		w=r;
		s=0;
		while(w!=0){
			w/=2;
			s++;
		}
		for(j=q;j<=s+1;j++){
		    o=1; 
		    if((p-o-1)>=l&&(p-o-1)<=r)ans++;//cout<<p-o-1<<endl;
			for(k=1;k<j-1;k++){
			    o*=2;
				if((p-o-1)>=l&&(p-o-1)<=r)ans++;//cout<<p-o-1<<endl;	
			}
			p*=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
