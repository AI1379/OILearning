#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
int main() {
	freopen("vowel.in","r",stdin);
	freopen("vowel.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++) {
		switch(s[i]) {
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				ans++;
		}
	}
	cout<<ans;
}
