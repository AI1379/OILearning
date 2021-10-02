#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++)
	    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
	        ans++;
	cout<<ans;
	return 0;
}
