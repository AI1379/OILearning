#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("twonum.in","r",stdin);
   freopen("twonum.out","w",stdout);
   int s1[100001],s2[100001];
   int t,m,h1,a1,x1,y1,h2,a2,x2,y2,x,y,z,a,b,c,w1,w2,o=1,j,l,q,e;
   cin>>t;
   for(int i=1;i<=t;i++) 
   { 
     cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
     int t1=0;
     int t2=0;
     w1=h1;w2=h2;
     while(1>0)
	 {
	   w1=(x1*w1+y1) % m;
	   if(s1[t1]!=s1[1]||t1<2)
	   {
	   	t1++;
	   s1[t1]=w1;
       } else break;
	 }t1--;
	 while(1>0)
	 {
	   w2=(x2*w2+y2) % m;
	    if(s2[t2]!=s2[1]||t2<2)
	   {
	   	t2++;
	   s2[t2]=w2;
       } else break;
    }t2--;
    s1[0]=s1[t1];
    o=t1+1;
    while(o<=10000)
	{
	  s1[o]=s1[o%t1];
	  o++;	
	}
	o=t2+1;
	s2[0]=s2[t2];
	while(o<=10000)
	{
	  s2[o]=s2[o%t2];
	  o++;	
	}
	j=1;
    for(;j<=10000;j++)
	{
		if(s1[j]==s2[j]) {
		cout<<j<<endl;break;}
	}if (j==10000) cout<<"-1"<<endl;//cout<<s1[4]<<" "<<s2[4]; 
   }	
}
