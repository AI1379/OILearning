#include<bits/stdc++.h>
using namespace std;
const int table[5][5]={
  {5,-1,-2,-1,-3},
  {-1,5,-3,-2,-4},
  {-2,-3,5,-2,-2},
  {-1,-2,-2,5,-1},
  {-3,-4,-2,-1,0}
};
int f[110][110];
int a[110],b[110],la,lb;
int main(){
  int i,j;
  char c;
  string sa,sb;
  cin>>la>>sa>>lb>>sb;
  for(i=1;i<=la;i++)
    {
        if(sa[i-1]=='A') a[i]=0;
        if(sa[i-1]=='C') a[i]=1;
        if(sa[i-1]=='G') a[i]=2;
        if(sa[i-1]=='T') a[i]=3;
    }
    for(i=1;i<=lb;i++)
    {
        if(sb[i-1]=='A') b[i]=0;
        if(sb[i-1]=='C') b[i]=1;
        if(sb[i-1]=='G') b[i]=2;
        if(sb[i-1]=='T') b[i]=3;
    }
  for(i=1;i<=la;i++) f[i][0]=f[i-1][0]+table[a[i]][4];
  for(i=1;i<=lb;i++) f[0][i]=f[0][i-1]+table[b[i]][4];
  for(i=1;i<=la;i++){
    for(j=1;j<=lb;j++){
      f[i][j]=max(f[i][j],max(f[i-1][j-1]+table[a[i]][b[j]],max(f[i-1][j]+table[a[i]][4],f[i][j-1]+table[4][b[j]])));
    }
  }
  cout<<f[la][lb];
  return 0;
}
