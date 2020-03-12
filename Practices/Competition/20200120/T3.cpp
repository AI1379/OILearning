#include <bits/stdc++.h>
using namespace std;
int n,m;
struct sis
{
    int c, t;
};
struct tsk
{
    int u, v;
};
stack<tsk> stk;
sis girl[5010];
void cpt(int a, int b, int c)
{
    int rst;
    rst = (a + b) / c;
    if (rst * c != a + b)
        rst++;
    return rst;
}
int main()
{
    int i,j;
    tsk tmp;
    for(i=1;i<=n-1;i++){
        cin>>tmp.u>>tmp.v;
        stk.push(tmp);
    }
}