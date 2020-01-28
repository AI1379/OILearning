#include<bits/stdc++.h>
using namespace std;
int n,a1,b1,a2,b2;
int main(){
	freopen("intersect.in","r",stdin);
	freopen("intersect.out","w",stdout);
	cin>>n>>a1>>b1>>a2>>b2;
	if(a1*a2==b1*b2) cout<<b1*b2;
	else{
		if(a1*a2>b1*b2)
		    if(a1*a2+b1*b2==0) cout<<b1*b2;
		    else cout<<a1*a2;
		else if(a1*a2+b1*b2==0) cout<<a1*a2;
		     else cout<<b1*b2;
	}
	cout<<".00";
}
