#include<bits/stdc++.h>
using namespace std;
int f[30010],v[35],w[35],p;
int m,n;
int main(){
  int i,j;
  cin>>n>>m;
  for(i=1;i<=m;i++){
    cin>>v[i]>>p;
    w[i]=v[i]*p;
  }
  for(i=1;i<=m;i++){
    for(j=n;j>=v[i];j--){
      f[j]=max(f[j],f[j-v[i]]+w[i]);
    }
  }
  cout<<f[n];
  return 0;
}
