#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
	long long x=a,y=b,r;
	while(y!=0){
		r=x%y;
		a=b;
		b=r;
	}
	return y;
}
int main(){
	long long A,B,b,k,x1,y1,x2,y2,tmp1,tmp2;
	while(cin>>x1>>y1>>x2>>y2){
		if(x1==0){
			if(x2==0){
				cout<<"Error"<<endl;
				continue;
			}
			A=y1;
		}
		else{
			if(y2==0){
				cout<<"Error"<<endl;
				continue;
			}
			A=x1;
		}
		if(x2==0)	B=y2;
		else	B=x2;
		if(A==0||B==0){
			cout<<"Error"<<endl;
			continue;
		}
		b=A;
		k=(0-A)/B;
		cout<<"y=";
		if(k*B!=0-A){
			tmp1=(0-A)/gcd((0-A),B);
			tmp2=B/gcd((0-A),B);
			if(tmp1<0&&tmp2>=0||tmp2<0&&tmp1>=0)
				cout<<'-';
			cout<<abs(tmp1)<<'/'<<abs(tmp2);
		}
		else{
			if(k==-1)
				cout<<'-';
			else if(k!=1)
				cout<<k;
		}
		cout<<'x';
		if(b>0)
			cout<<'+';
		cout<<b<<endl;
	}
	return 0;
}
