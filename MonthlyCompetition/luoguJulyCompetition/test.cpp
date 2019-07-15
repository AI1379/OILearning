#pragma GCC optimize(5)//O5优化
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define LOLO long long
using namespace std;
LOLO AA,Ta,Ans,GG[1005],A[1000005],N,B[1000005],C[1000005];
LOLO L_B(LOLO x){return x&(-x);}
inline LOLO Read()
{
    LOLO x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
inline void Write(LOLO x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)
    {
        Write(x/10);
    }
    putchar(x%10+'0');
}
void Add(LOLO X,LOLO Num)
{
    for(LOLO i=X;i<=N;i+=L_B(i))
    {
        C[i]+=Num;
    }
}
LOLO Ask(LOLO x)
{
    LOLO Ans=0;
    for(LOLO i=x;i;i-=L_B(i))
    {
        Ans+=C[i];
    }
    return Ans;
}
int main()
{
    N=Read();
    for(LOLO i=1;i<=N;i++)A[i]=Read(),B[i]=A[i];
    sort(B+1,B+1+N);
    LOLO Num=unique(B+1,B+N+1)-B-1;
    for(LOLO i=1;i<=N;i++)A[i]=lower_bound(B+1,B+1+Num,A[i])-B;
    for(LOLO i=N;i>=1;i--)//枚举区间长度 
    {
        LOLO Num=0;
        Num=(Ask(A[i]-1))*i;
        Add(A[i],N-i+1);
        Ans+=Num;
    }
    Write(Ans);
    system("pause");
    return 0;
}