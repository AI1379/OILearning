#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("vowel.in","r"stdin);
	freopen("vowel.out","w"stdout);
	string a;
	cin>>a;
	int l=a.size(),ans=0;
	for(int i=0;i<l;i++){
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'){
			ans+=1;
		}
	}
	cout<<ans;
}
