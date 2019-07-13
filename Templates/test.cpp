#include <bits/stdc++.h>
#include "mathematics.hpp"
using namespace std;
int main(){
  int prime[Maxn];
  int n;
  double num;
  cin>>n;
  num=root(n,2,0.0000001);
  cout<<fixed<<setprecision(7)<<num;
  system("pause");
  return 0;
}
