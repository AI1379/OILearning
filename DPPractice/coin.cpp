#include<bits/stdc++.h>
using namespace std;
int f[100010],w[60];
int n,t;
int main(){
  int i,j;
  cin>>n>>t;
  for(i=1;i<=n;i++)
    cin>>w[i];
  for(i=1;i<=n;i++){
    for(j=1;j<=t;j++){
      f[j]=min(f[j],f[j-w[i]]+w[i]);
    }
  }
  cout<<f[t];
  return 0;
}
