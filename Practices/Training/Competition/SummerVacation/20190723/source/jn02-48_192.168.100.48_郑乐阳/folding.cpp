#include<bits/stdc++.h>
using namespace std;

int w1,h1,w2,h2;

int lowpow(int a,int b)
{
	if(a>=b)
		return 0;
	else
		return lowpow(a*2,b)+1;
}

int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	scanf("%d%d%d%d",&w1,&h1,&w2,&h2);
	if(w1>h1)
		swap(w1,h1);
	if(w2>h2)
		swap(w2,h2);
	if(w1<w2||h1<h2)
	{
		cout<<"-1";
		return 0;
	}
	int tmp=lowpow(w2,w1)+lowpow(h2,h1);
	if(h2<w1)
		tmp=min(tmp,lowpow(w2,h1)+lowpow(h2,w1));
	cout<<tmp;
	return 0;
}

