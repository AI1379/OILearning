#include <bits/stdc++.h>
using namespace std;
class point
{
public:
    double x, y;
    int quad;
    void initpoint(double a, double b)
    {
        x = a;
        y = b;
        if (x > 0 && y > 0)
            quad = 1;
        else if (x < 0 && y > 0)
            quad = 2;
        else if (x < 0 && y < 0)
            quad = 3;
        else if (x > 0 && y < 0)
            quad = 4;
        else
            quad = 0;
    }
};
class target : public point
{
public:
    double itsx, itsy;
    bool ixax, iyax;
    void inittarget(point s, double a, double b)
    {
        initpoint(a,b);
        if (x * s.x < 0)
        {
            iyax = true;
            itsy = (x * s.y - s.x * y) / (x - s.x);
        }
        if (y * s.y > 0)
        {
            ixax = true;
            itsx = -(x * s.y - s.x * y) / (y - s.y);
        }
    }
};
bool cmpx(target a,target b){
    return a.x-b.x>0;
}
bool cmpy(target a,target b){
    return a.y-b.y>0;
}
point umi;
vector<target>lst;
int nopsq[5]={0,0,0,0,0};
int n,k;
int main()
{
    int x,y,i;
    target tmp;
    cin>>x>>y;
    umi.initpoint((double)(x),(double)(y));
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>x>>y;
        tmp.inittarget(umi,(double)(x),(double)(y));
        nopsq[tmp.quad]++;
        lst.push_back(tmp);
    }
    if((nopsq[umi.quad]>k)||()){
        cout<<"-1";
        return 0;
    }
}