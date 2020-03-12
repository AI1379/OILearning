#include <bits/stdc++.h>
using namespace std;
int n,t,type;
int a[1010];
int f[1010][1010];
int main()
{
    int i,j,k;
    cin>>n>>t>>type;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++){
        for(j=1;j<=t;j++){
            f[i][j]=f[i-1][j];
            for(k=-f[i-1][j];k<=a[i]&&k<=j;k++){
                f[i][j]=max(f[i][j],f[i-1][j-k]+k);
            }
        }
    }
    cout<<f[n][t];
    system("pause");
    return 0;
}