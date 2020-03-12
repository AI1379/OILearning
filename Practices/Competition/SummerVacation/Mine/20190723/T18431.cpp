#include<bits/stdc++.h>
using namespace std;
const int MOD1=100000007;
const int B1=37;
const int MOD2=100000003;
const int B2=41;
unsigned long long n1[100001],m1,n2[100001],m2,e1[100001],e2[100001];
unsigned long long len1,len2,i,ans=0;
string s,t;
int main(){
	cin>>s>>t;
	e1[0]=1;
	e2[0]=1;
	len1=s.length();
	len2=t.length();
	for(i=1;i<=100000;i++){
		e1[i]=e1[i-1]*B1%MOD1;
		e2[i]=e2[i-1]*B2%MOD2;
	}
	for(i=1;i<=len1;i++){
		n1[i]=(n1[i-1]*B1+(unsigned long long)(s[i-1]))%MOD1;
		n2[i]=(n2[i-1]*B2+(unsigned long long)(s[i-1]))%MOD2;
	}
	for(i=1;i<=len2;i++){
		m1=(m1*B1+(unsigned long long)(t[i-1]))%MOD1;
		m2=(m2*B2+(unsigned long long)(t[i-1]))%MOD2;
	}
	for(i=1;i<=len1-len2+1;i++){
		if(m1==(n1[i+len2-1]-(n1[i-1]*e1[len2]%MOD1)+MOD1)%MOD1&&m2==(n2[i+len2-1]-(n2[i-1]*e2[len2]%MOD2)+MOD2)%MOD2){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
