#include<bits/stdc++.h>
using namespace std;
long long m,n,w,h,ans1,ans2 ,ansm,a1=0,a2=0,aa=100000000009,b1=0,b2=0,bb=100000000009,aaa=100000000009,bbb=100000000009,a3,a4,b3,b4;
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>m>>n>>w>>h;
 
	if((w>m&&w>n)||(h>m&&h>n)||(w>m&&h>n)||(w>n&&h>m)){
		cout<<-1<<endl;
		return 0;
	}
	if(m>=w&&n>=h){
		int k1=m-w,k2=n-h,k3=m-w,k4=n-h,p,q;
		if(k1!=0){
			while(k1>=w){
			k1-=w;
			a1++;
		}
		if(k1>0) a1++;
		}
			if(k2!=0){
			while(k2>=h){
			k2-=h;
			a2++;
		}
		if(k2>0) a2++;
		}
		aa=a1+a2;
		p=m/2;
		q=n/2;
		if(m>w){
			while(p>w+k3-p) p-=0.5;
		a3++;
		k3-=p;
		if(k3!=0){
			while(k3>=w){
			k3-=w;
			a3++;
			}
		}
		if(k3>0) a3++;
		}
		if(n>h){
			while(q>h+k4-q) q-=0.5;
		a4++;
		k4-=q;
		if(k4!=0){
			while(k4>=h){
			k4-=h;
			a4++;
		}
		if(k4>0) a4++;}
		
		}
		aaa=a3+a4;
	}
	if(m>=h&&n>=w){
		int k1=m-h,k2=n-w,k3=m-h,k4=n-w,p,q;
		if(k1!=0){
			while(k1>=h){
			k1-=h;
			b1++;
		}
		if(k1>0) b1++;
		}
			if(k2!=0){
			while(k2>=w){
			k2-=w;
			b2++;
			}
		if(k2>0) b2++;
		}
		bb=b1+b2;
		p=m/2;
		q=n/2;
		if(m>h){
			while(p>h+k3-p) p-=0.5;
		b3++;
		k3-=p;
		if(k3!=0){
			while(k3>=h){
			k3-=h;
			b3++;
		}
		if(k3>0) b3++;}
		}
		if(n>w){
			while(q>w+k4-q) q-=0.5;
		b4++;
		k4-=q;
		if(k4!=0){
			while(k4>=w){
			k4-=w;
			b4++;}
		
		if(k4>0) b4++;}
		}
		
	    bbb=b3+b4;
	}
	ans1=min(aa,bb);
	ans2=min(aaa,bbb);
	ansm=min(ans1,ans2);
	cout<<ansm<<endl;
	return 0;
}

