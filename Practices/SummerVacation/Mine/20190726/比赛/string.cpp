#include<bits/stdc++.h>
using namespace std;
const int MOD=100000007;
const int B=37;
unsigned long long n[1000001],m,e[100001],k;
vector<int>pos;
void match(string s,string t,int len1,int len2){
	int i;
	e[0]=1;
	len1=s.length();
	len2=t.length();
	for(i=1;i<=100000;i++)
		e[i]=e[i-1]*B%MOD;
	for(i=1;i<=len1;i++)
		n[i]=(n[i-1]*B+(unsigned long long)(s[i-1]))%MOD;
	for(i=1;i<=len2;i++)
		m=(m*B+(unsigned long long)(t[i-1]))%MOD;
	for(i=1;i<=len1-len2+1;i++){
		if(m==(n[i+len2-1]-(n[i-1]*e[len2]%MOD)+MOD)%MOD){
			pos.push_back(i);
			cout<<i<<' ';
			k++;
		}
	}
	return ;
}
int main(){
	string s,t;
	int i,j,ls,lt,ans=0,tmp;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s>>t;
	ls=s.length();
	lt=t.length();
	match(t,s,lt,ls);
	cout<<endl;
	for(i=0;i<=lt-ls;i++){
		tmp=0;
		for(j=i;j<=k;j++){
			if(j==i||pos[j]-pos[j-1]>=ls)tmp++;
		}
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}
