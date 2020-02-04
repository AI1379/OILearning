#include<bits/stdc++.h>
using namespace std;
int m,n;
int f[32010],miw[32010],mic[32010],aiw[32010][3],aic[32010][3];
int main(){
  int i,j,v,p,q;
  cin>>n>>m;
  for(i=1;i<=m;i++){
    cin>>v>>p>>q;
    if(q==0){
      miw[i]=v;
      mic[i]=v*p;
    }
    else{
      aiw[q][0]++;
      aiw[q][aiw[q][0]]=v;
      aic[q][aiw[q][0]]=v*p;
    }
  }
  for(i=1;i<=m;i++){
    for(j=n;miw[i]!=0&&j>=miw[i];j--){
      f[j]=max(f[j],f[j-miw[i]]+mic[i]);
      if(j>=miw[i]+aiw[i][1])f[j]=max(f[j],f[j-miw[i]-aiw[i][1]]+mic[i]+aic[i][1]);
      if(j>=miw[i]+aiw[i][2])f[j]=max(f[j],f[j-miw[i]-aiw[i][2]]+mic[i]+aic[i][2]);
      if(j>=miw[i]+aiw[i][1]+aiw[i][2])f[j]=max(f[j],f[j-miw[i]-aiw[i][1]-aiw[i][2]]+mic[i]+aic[i][1]+aic[i][2]);
    }
  }
  cout<<f[n];
  return 0;
}
