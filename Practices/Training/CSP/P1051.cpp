#include <bits/stdc++.h>
using namespace std;
struct student
{
    string name;
    int avg, cls;
    int papers;
    bool wk, wst;
    int sal;
    int pos;
};
student input(int pos)
{
    student in;
    char x, y;
    cin >> in.name >> in.avg >> in.cls >> x >> y >> in.papers;
    in.wk = (x == 'Y');
    in.wst = (y == 'Y');
    in.pos = pos;
    return in;
}
bool cmp(student A, student B)
{
    if (A.sal == B.sal)
        return A.pos < B.pos;
    return A.sal > B.sal;
}
int n;
int ans = 0;
vector<student> lst;
int main()
{
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cin >> n;
    for (int i = 0; i < n; i++)
        lst.push_back(input(i));
    for (int i = 0; i < n; i++)
    {
        int sali = 0;
        if (lst[i].avg > 80 && lst[i].papers >= 1)
            sali += 8000;
        if (lst[i].avg > 85 && lst[i].cls > 80)
            sali += 4000;
        if (lst[i].avg > 90)
            sali += 2000;
        if (lst[i].avg > 85 && lst[i].wst)
            sali += 1000;
        if (lst[i].avg > 80 && lst[i].wk)
            sali += 850;
        lst[i].sal = sali;
        ans += sali;
    }
    sort(lst.begin(), lst.end(), cmp);
    cout << lst[0].name << lst[0].sal << ans;
    return 0;
}