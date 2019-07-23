#include<bits/stdc++.h>
using namespace std;
int T,ans;
long long h1,a1,x1,yy,h2,a2,x2,y2,m,t1,t2,p1,p2;
bool vis1[1000001],vis2[1000001];
int main(){
	freopen("twonum.in","r",stdin);
	freopen("twonum.out","w",stdout);
	cin>>T;
	while(T--){
		t1=-1,t2=-1;
		ans=0;
		bool flag1=true,flag2=true,first1=true,first2=true;
		cin>>m>>h1>>a1>>x1>>yy>>h2>>a2>>x2>>y2;
		for(int i=0;i<m;i++){
			vis1[i]=1;
			vis2[i]=1;
		}
		while(flag1||flag2){
			ans++;
			h1=(h1*x1+yy)%m;
			h2=(h2*x2+y2)%m;
			if(vis1[h1]){
				vis1[h1]=0;
			}
			else{
				if(first1){
					p1=ans-1;
					flag1=false;
					first1=false;
				}
			}
			if(vis2[h2]){
				vis2[h2]=0;
			}
			else{
				if(first2){
					p2=ans-1;
					flag2=false;
					first2=false;
				}
			}
			if(a1==h1&&first1) t1=ans;
			if(a2==h2&&first2) t2=ans;		
		}
		//cout<<t1<<" "<<p1<<" "<<t2<<" "<<p2<<endl;
		if(t1==-1||t2==-1){
			cout<<-1<<endl;
		}
		else{
			bool vis3[1000001];
			for(int i=0;i<p2;i++) vis3[i]=true;
			int p=0;
			if(p1<p2) swap(p1,p2),swap(t1,t2);
			while(1){
				if((p*p1+t1)%p2==t2){
					cout<<p*p1+t1<<endl;
					break;
				}
				else{
					if(vis3[(p*p1+t1)%p2])vis3[(p*p1+t1)%p2]=false;
					else{
						cout<<-1<<endl;
						break;
					}
				}
				p++;
			}
		}
	}  
}
