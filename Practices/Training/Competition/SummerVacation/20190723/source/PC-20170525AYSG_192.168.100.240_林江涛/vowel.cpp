#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int i,len,ans=0;
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	cin>>s;
	len=s.length();
	for(i=0;i<len;i++)
		if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			ans++;
	cout<<ans;
	return 0;
}
