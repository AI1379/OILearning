#include<bits/stdc++.h>
using namespace std;
int t,m;
int f[100010],v[10010],w[10010];
int main(){
  int i,j;
  cin>>t>>m;
  for(i=1;i<=m;i++)
    cin>>v[i]>>w[i];
  for(i=1;i<=m;i++){
    for(j=v[i];j<=t;j++){
      f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
  }
  cout<<f[t];
  return 0;
}
