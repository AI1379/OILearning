#include<bits/stdc++.h>
using namespace std;
bool judge(int a,int b,int c,int mid){
  return a>=0&&b>=0&&a+b+c>=mid&&(a+b)>=mid>>1&&(b+c)>=mid>>1&&(a+c)>=mid>>1;
}
int main(){
  int n,a,b,c,mid,l,r,i;
  cin>>n;
  for(i=0;i<n;i++){
    cin>>a>>b>>c;
    l=1;r=1<<30;
    while(l+1<r){
      mid=(l+r)>>1;
      if(judge(a-mid,b-mid,c,mid))l=mid;
      else r=mid;
    }
    cout<<l<<endl;
  }
  return 0;
}
