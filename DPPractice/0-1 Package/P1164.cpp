#include<bits/stdc++.h>
using namespace std;
int f[10010],v[110];
int m,n;
int main(){
  int i,j;
  cin>>n>>m;
  f[0]=1;
  for(i=1;i<=n;i++)cin>>v[i];
  for(i=1;i<=n;i++){
    for(j=m;j>=v[i];j--){
      f[j]+=f[j-v[i]];
    }
  }
  cout<<f[m];
  return 0;
}
