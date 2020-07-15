#include<bits/stdc++.h>
using namespace std;
const int b=13;
int main(){
    string s;
    char c;
    int i,j,len;
    int hash[1000000];
    do{
        vector<int>lst;
        memset(hash,0,sizeof(hash));
        cin>>s;
        c=s[0];
        if(c=='.'&&len==1)break;
        len=s.length();
        for(i=0;i<len;i++){
            if(s[i]==c){
                lst.push_back(i);
            }
            hash[i]=((int)(s[i])-(int)('a'))*b;
        }

    }while(true)
}