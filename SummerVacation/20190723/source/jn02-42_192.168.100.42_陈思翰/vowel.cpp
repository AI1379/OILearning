#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	string s;
	int ans,l;
	map<char,bool> a;
	a['a']=1;
	a['e']=1;
	a['i']=1;
	a['o']=1;
	a['u']=1;
	a['A']=1;
	a['E']=1;
	a['I']=1;
	a['O']=1;
	a['U']=1;
	getline(cin,s);
	l=s.size();
	for(int i=0;i<l;i++){
		if(a[s[i]])ans++;
	}
	cout<<ans;
	return 0;
}
