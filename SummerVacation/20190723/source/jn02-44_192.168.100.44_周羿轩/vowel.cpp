#include<bits/stdc++.h>
using namespace std;
string s,v="aeiouAEIOU";
int a;
int main(){
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<=9;j++){
			if(s[i]==v[j]) a++;
		}
	}
	cout<<a;
	return 0;
} 
