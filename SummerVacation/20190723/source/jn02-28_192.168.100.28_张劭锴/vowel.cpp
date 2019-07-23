#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	string s;
	int ans=0,len;
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U')
			ans++;
	}
	cout<<ans;
	return 0;
}
