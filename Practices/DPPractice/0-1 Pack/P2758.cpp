#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int len1,len2;
int f[2010][2010];
int diff(int i,int j){
    if(s1[i-1]==s2[j-1])return 0;
    else return 1;
}
int main(){
    int i,j;
    cin>>s1>>s2;
    len1=s1.length();len2=s2.length();
    for(i=0;i<=len1;i++)f[i][0]=i;
    for(i=0;i<=len2;i++)f[0][i]=i;
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            f[i][j]=min(f[i-1][j]+1,min(f[i][j-1],f[i-1][j-1]+diff(i,j)));
        }
    }
    cout<<f[len1][len2];
    return 0;
}
