//Coded by dst 
#include<iostream>
#include<cstdio>
using namespace std;
char mp[1000];
string s;
int len,ans;
int main(){
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	mp['a']=mp['A']=mp['e']=mp['E']=mp['i']=mp['I']=mp['o']=mp['O']=mp['u']=mp['U']=1;
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++)
		ans+=mp[s[i]];
	printf("%d",ans);
	return 0;
} 
