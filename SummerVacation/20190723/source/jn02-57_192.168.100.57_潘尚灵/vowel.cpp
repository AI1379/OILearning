#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	string s;
	int ans,size,i;
	cin>>s;
	size=s.size();
	for(i=0;i<size;i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			ans++;
		if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
