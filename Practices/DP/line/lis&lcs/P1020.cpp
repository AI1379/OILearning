#include<bits/stdc++.h>
using namespace std;
int h[100010],f[100010];
int n,x;
int main(){
  int i,j,ans1=0,ans2=0;
  while(cin>>x){
    n++;
    h[n]=x;
  }
  for(i=1;i<=n;i++){
    for(j=1;j<i;j++){
      if(h[j]>=h[i]){
        f[i]=max(f[i],f[j]);
      }
    }
    f[i]++;
  }
  for(i=1;i<=n;i++)ans1=max(ans1,f[i]);
  for(i=1;i<=n;i++){
    int wh=0,nowh=1<<30;
    for(j=1;j<=ans2;j++)
      if(f[j]>=h[i]&&f[j]<nowh)
        nowh=f[j],wh=j;
    if(wh)f[wh]=h[i];
    else f[++ans2]=h[i];
  }
  cout<<ans1<<endl<<ans2;
  return 0;
}
