#include<bits/stdc++.h>
using namespace std;
double bc(double x){
	double mid=x/2.0;
	return sqrt(mid*mid*2);
}
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	double a=0,b=0,c=0,l;
	int n,k,s=0,hm=1;
	cin>>n>>k;
	l=n;
	while(k>0){
		if(hm==1) a+=l,hm++;
		else if(hm==2) b+=l,hm++;
		else if(hm==3) c+=l,hm=1;
		s++;
		if(s%4==0){
			s=0;
			k--;
			l=bc(l);
		}
	}
	cout<<fixed<<setprecision(3)<<a<<" "<<b<<" "<<c;
	
	return 0;
} 
