#include<bits/stdc++.h>
using namespace std;
const int MOD=100000007;
const int B=37;
unsigned long long n[100001],m,e[100001];
unsigned long long len1,len2,i,k,num,ans=0;
string s,t;
int main(){
	cin>>t>>num;
	e[0]=1;
	len2=t.length();
	for(i=1;i<=100000;i++)
		e[i]=e[i-1]*B%MOD;
	for(i=1;i<=len2;i++)
		m=(m*B+(unsigned long long)(t[i-1]))%MOD;
	for(k=0;k<num;k++){
		cin>>s;
		len1=s.length();
		for(i=1;i<=len1;i++)
			n[i]=(n[i-1]*B+(unsigned long long)(s[i-1]))%MOD;
		for(i=1;i<=len1-len2+1;i++){
			if(m==(n[i+len2-1]-(n[i-1]*e[len2]%MOD)+MOD)%MOD){
				ans++;
			}
		}
	}
	return 0;
}
