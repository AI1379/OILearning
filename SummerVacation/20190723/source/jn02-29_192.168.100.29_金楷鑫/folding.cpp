#include<bits/stdc++.h>
using namespace std;
long long x,y,z,a,b,c,d,a1,a2,a3,a4,b1=0,b2=0,b3=0,b4=0;
long long W,H,w,h;
int main()
{ 
  freopen("folding.in","r",stdin);
  freopen("folding.out","w",stdout);
  cin>>W>>H>>w>>h;
  if(H>W) 
  {
  	a=W;
  	W=H;
  	H=a;
  }	
  if(h>w)
  {
  	a=w;
  	w=h;
  	h=a;
  } 
  if(h>W||w>W||(W>w&&h>H))
  cout<<"-1";
  else
  { if(w==W&&h==H) cout<<"0";
  else  if (H<w)
    {
      a1=w;	
      while(a1<W)
		{
			a1=a1*2;
			b2++;
		}
	  a2=h;
		while(a2<H)
		{
			a2=a2*2;
			b4++;
		}
		cout<<b2+b4;
	}
  	else 
	  {
  	    a1=w;
		a2=h;
		while(a1<W)
		{
			a1=a1*2;
			b1++;
		}	
		a1=w;
		while(a1<H)
		{
			a1=a1*2;
			b2++;
		}
		while(a2<W)
		{
			a2=a2*2;
			b3++;
		}
		a2=h;
		while(a2<H)
		{
			a2=a2*2;
			b4++;
		}
		if((b1+b4)>(b2+b3)) cout<<b2+b3;else cout<<b1+b4;
	  }
  }
}
