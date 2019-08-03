#include<bits/stdc++.h>
using namespace std;
int t,n,a[500000];
int judge(int p){
    int i,time=0;
    for(i=0;i<n;i++)
        time+=(p/a[i]);
    if(time==t)return 0;
    if(time<t) return -1;
    if(time>t) return 1;
}
int main(){
    int l,r,mid,i,check,ans=0x7fffff;
    bool flag;
    cin>>n>>t;
    for(i=0;i<n;i++)
        cin>>a[i];
    l=0;r=100000000;
    flag=false;
    while(l<r){
        mid=(l+r)>>1;
        check=judge(mid);
        if(check==0){
            ans=min(ans,mid);
            flag=true;
            r=mid-1;
        }
        if(check==-1)l=mid+1;
        else r=mid-1;
    }
    if(flag)cout<<ans;
    else cout<<"The probability of existence of p is 0%.";
    return 0;
}