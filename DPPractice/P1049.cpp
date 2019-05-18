#include<bits/stdc++.h>
using namespace std;
int V,n;
int f[20010],v[40];
int main(){
  int i,j;
  cin>>V>>n;
  for(i=1;i<=n;i++)
    cin>>v[i];
  for(i=1;i<=n;i++){
    for(j=V;j>=v[i];j--){
      if(f[j]<f[j-v[i]]+v[i]){
        f[j]=f[j-v[i]]+v[i];
      }
    }
  }
  cout<<V-f[V];
  return 0;
}
