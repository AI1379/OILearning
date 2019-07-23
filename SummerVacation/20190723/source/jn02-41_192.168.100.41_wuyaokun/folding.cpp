#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double a,b,c,d;
int ans;
int get(double a,double b)
{
    int res=0;
    while (a/2.0>b)
    {
        a/=2.0;
        res++;
    }
    if(a-b>=0.0000001) res++;
    return res;
}
int main()
{
	freopen("folding.in","r",stdin);
    freopen("folding.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(c>a||d>b) 
    {
        puts("-1");
        return 0;
    } 
    if(c==a&&d==b) 
    {
        puts("0");
    }  
    ans+=get(a,c);
    ans+=get(b,d);
    cout<<ans;

}
