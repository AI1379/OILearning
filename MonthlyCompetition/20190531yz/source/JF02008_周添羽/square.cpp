#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
double  a,n,k,ans1,ans2,ans3;

int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
    scanf("%lf%lf",&n,&k);
    int p=1;
    for(int i=1;i<=k*4;i++)
    {
    if(i%3==1)ans1+=n;
    else if(i%3==2)ans2+=n;
    else ans3+=n;
    if(p%4==0){
    	n/=2;
    	n*=sqrt(2);}
	p++;
    
	}
    printf("%.3lf %.3lf %.3lf",ans1,ans2,ans3);
}


