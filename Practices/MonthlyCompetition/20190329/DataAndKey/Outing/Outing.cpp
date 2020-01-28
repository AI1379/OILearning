#include <cstdio>  
#include <iostream>
#include <cstring> 
#include <cstdlib>

using namespace std;
 
long long pow_mod(long long a,long long n,long long m)
{
	if (n==0) return 1;
	if (n==1) return a%m;
	long long x=pow_mod(a,n/2,m);
	long long ans=(long long)x*x%m;
	if (n%2) ans=ans*a%m;
	return (long long)ans;
}

long long n,k;  
long long w;

int main() 
{
    cin>>n>>k;
    w=pow_mod(n,n,k)-n%k+1;  
   // cout<<w<<endl;
    for (;w<0;w+=k);
    cout<<w%k<<endl;
	return 0; 
}
