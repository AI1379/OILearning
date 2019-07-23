#include<bits/stdc++.h>
using namespace std;
string s;
int ans=0;
int main(){
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U') ans++;
	}
	cout<<ans;
	return 0;
}
