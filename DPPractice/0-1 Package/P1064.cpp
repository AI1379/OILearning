#include<bits/stdc++.h>
using namespace std;
int m,n;
int f[32010],miv[70],miw[70],aiv[70][3],aiw[70][3];
int main(){
  int i,j,v,p,q;
  cin>>n>>m;
  for(i=1;i<=m;i++){
    cin>>v>>p>>q;
    if(q==0){
      miv[i]=v;
      miw[i]=v*p;
    }
    else{
      aiv[q][0]++;
      aiv[q][aiv[q][0]]=v;
      aiw[q][aiv[q][0]]=v*p;
    }
  }
  for(i=1;i<=m;i++){
    for(j=n;miv[i]!=0&&j>=miv[i];j--){
      f[j]=max(f[j],f[j-miv[i]]+miw[i]);
      if(j>miv[i]+aiv[i][1])f[j]=max(f[j],f[j-aiv[i][1]]+aiw[i][1]);
      if(j>miv[i]+aiv[i][2])f[j]=max(f[j],f[j-aiv[i][2]]+aiw[i][2]);
      if(j>miv[i]+aiv[i][1]+aiv[i][2])f[j]=max(f[j],f[j-aiv[i][1]-aiv[i][2]]+aiw[i][1]+aiw[i][2]);
    }
  }
  cout<<f[n];
  return 0;
}
