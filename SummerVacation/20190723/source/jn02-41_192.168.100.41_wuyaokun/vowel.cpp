#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s;
int ans=0;
bool pd(char x)
{
    if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u') return 1;
    if(x=='A'||x=='E'||x=='I'||x=='O'||x=='U') return 1;
    return 0;
}
int main()
{
    freopen("vowel.in","r",stdin);
    freopen("vowel.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(pd(s[i])) ans++;
    printf("%d",ans);
}