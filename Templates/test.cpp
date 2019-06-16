#include<bits/stdc++.h>
using namespace std;
int mian(){
  int ans=0,i;
  for(i=1;i<=31;i++)ans+=(1<<i);
  cout<<ans;
  return 0;
}
