#include <bits/stdc++.h>
using namespace std;
int n,a[100001],k[100001],x[100001],i;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        k[a[i-1]]=a[i];
        x[a[i]]=a[i-1];
    }
    for(i=n;i>=1;i--){
        if(k[i]){
            cout<<i<<' '<<k[i]<<' ';
            k[x[i]]=k[k[i]];
            x[k[x[i]]]=x[i];
            k[k[i]]=0;
        }
    }
    return 0;
}