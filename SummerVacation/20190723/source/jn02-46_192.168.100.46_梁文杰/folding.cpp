#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int w1,h1,w2,h2,b,t;
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	cin>>w1>>h1>>w2>>h2;
	if (w1>h1)
		swap(w1,h1);
	if (w2>h2)
		swap(w2,h2);
	if (w1<w2||h1<h2){
		cout<<-1;
		return 0;
	}
	cout<<h2/h1-1;
	return 0;
}
