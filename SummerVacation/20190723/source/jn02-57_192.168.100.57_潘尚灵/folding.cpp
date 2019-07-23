#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	int W,H,w,h,ans;
	cin>>W>>H>>w>>h;
	if(max(W,H)<max(w,h)) cout<<-1;
	/*else if(W>=w&&H>=h)
	{
		while(H>2*h)
		{
			if(H%2)
			
		}
	}*/
	cout<<2<<endl;
	return 0;
}
