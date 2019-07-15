#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
struct interval{
    int l,r;
};
bool cmp(interval A,interval B){
    if(A.r==B.r) return A.l<B.l;
    return A.r<B.r;
}
int main(){
    int n,i,j,k,tmp,ans,f[2010][4010],dp[2010][2010];
    interval people[2010];
    vector<int> q[4010];
    cin>>n;
    for(i=0;i<n;i++) cin>>people[i].l>>people[i].r;
    sort(people,people+n,cmp);
    for(i=0;i<n;i++)
        q[people[i].r].push_back(i);
    ans=n;
    for(i=1;i<n;i++){
        for(j=people[i].l;j<people[i].r;j++){
            f[i][j]=f[i][j-1];
            for(k=0;k<q[j].size();k++){
                if(q[j][k]<i){
                    tmp=q[j][k];
                    dp[i][tmp]=1;
                    if(people[tmp].l<=people[i].l)
                        dp[i][tmp]=(dp[i][tmp]+f[tmp][people[i].l-1])%MOD;
                    else
                        dp[i][tmp]=(dp[i][tmp]+f[i][people[tmp].l-1])%MOD;
                    f[i][j]=(f[i][j]+dp[i][tmp])%MOD;
                    ans=(ans+dp[i][tmp])%MOD;
                }
            }
        }
    }
    cout<<ans;
    system("pause");
    return 0;
}
