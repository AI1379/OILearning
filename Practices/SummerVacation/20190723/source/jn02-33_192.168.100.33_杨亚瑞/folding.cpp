#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	double W,H,w,h;int count=0;
	cin>>W>>H>>w>>h;
	if(max(W,H)<max(w,h)||min(W,H)<min(w,h))
	{
		cout<<"-1"<<endl;
		return 0;
	}
    if(max(W,H)!=max(w,h))
    {
    	double c=max(W,H);
         while(c>max(w,h))
         {   
         	c/=2.0;
         	count++;
		 }
	}
	 if(min(W,H)!=min(w,h))
    {
    	double m=min(W,H);
         while(m>min(w,h))
         {
         	m/=2.0;
         	count++;
		 }
	}
	cout<<count<<endl;
	return 0;
}
