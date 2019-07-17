#include<iostream>
using namespace std;
int c[maxn],v[maxn];
int main()
{
    int n,V;
    cin>>n>>V;
   //先逆序，从后向前，这样有利于输出时是按照最小字典序来
    for(int i=n;i>=1;i--)
        cin>>c[i]>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=V;j>=c[i];j--)
            f[j]=max(f[j],f[j-c[i]]+v[i]);
    for(int i=n;i>=1;i--)
        if(f[V]==f[V-c[i]]+v[i])//两者相同以选序号最小的情况为主
        {
            cout<<n-i+1<<' ';
            V-=c[i];
        }
	return 0;
}

