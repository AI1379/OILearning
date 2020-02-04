#include<bits/stdc++.h>
using namespace std;
const int MOD=100000007;
int main(){
    int T,m,n,f[310][310];
    int i,j,k,t;
    cin>>T;
    for(t=0;t<T;t++){
        cin>>m>>n;
        memset(f,0,sizeof(f));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(i==1)
                    f[i][j]=1;
                else{
                    f[i][j]=f[i-1][j];
                    for(k=1;k*i<=j;k++){
                        f[i][j]=(f[i][j]+f[i-1][j-k]-f[i-2][j-k])%MOD;
                    }
                }
            }
        }
        for(i=0;i<=n;i++){
            for(j=0;j<=m;j++){
                cout<<f[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<f[n][m]<<endl;
    }
    system("pause");
    return 0;
}