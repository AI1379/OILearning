#include<bits/stdc++.h>
using namespace std;
long long h1,h2; int a1,a2,x1,x2,yy,y2,m,t;
int main(){
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%lld%d%d%d%lld%d%d%d",&m,&h1,&a1,&x1,&yy,&h2,&a2,&x2,&y2);
		bool b1[1000005]={},b2[100005]={}; int ans=0,aa,bb,aaa,bbb;int f1=0,f2=0;
		while(1){
			if(f1>1&&f2>1){
				while(1){
					if((aaa+aa-bb)%bbb==0){
						cout<<aaa+aa<<endl; break;
					}
					aaa+=aaa;
				}
			    break;
			} 
			h1=((h1*x1)%m+yy)%m;
			h2=((h2*x2)%m+y2)%m;
			ans++;
			if(h1==a1){
			    f1++;
				if(f1==1) aa=ans; 
				if(f1==2) aaa=ans-aa;
			} 
			if(h2==a2){
				f2++;
				if(f2==1) bb=ans; 
				if(f2==2) bbb=ans-bb;
			} 
			if(b1[h1]&&!f1){
				cout<<-1<<endl; break;
			} 
			if(b2[h2]&&!f2){
				cout<<-1<<endl; break;
			}
			b1[h1]=1;
			b2[h2]=1;
		}
	}
	return 0;
}
