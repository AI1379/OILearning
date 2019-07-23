#include <bits/stdc++.h>
using namespace std;

int ans;
string s;

bool isvowel(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'
	 ||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
	 	return true;
	return false;
}

int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	cin>>s;
	for(int i=0 ; i<s.size() ; i++)
		if(isvowel(s[i])) ans++;
	cout<<ans;
	return 0;
}
