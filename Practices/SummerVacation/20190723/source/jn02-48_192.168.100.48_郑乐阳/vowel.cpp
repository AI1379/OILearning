#include<bits/stdc++.h>
using namespace std;

string s;
int sum=0;

int main()
{
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a'||s[i]=='o'||s[i]=='i'||s[i]=='u'||s[i]=='e')
			sum++;
	}
	cout<<sum;
	return 0;
}
