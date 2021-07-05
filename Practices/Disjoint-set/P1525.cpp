#include <bits/stdc++.h>
using namespace std;
struct relation
{
    int indexA, indexB;
    int angry;
};
bool cmp(relation A, relation B)
{
    return A.angry > B.angry;
}
relation relations[100000];
int fa[20000], enemy[20000];
int m, n;
int find(int node)
{
    if (fa[node] == node)
        return node;
    fa[node] = find(fa[node]);
    return fa[node];
}
int main()
{
#ifndef DEBUG
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    int i;
    memset(enemy, 0, sizeof(enemy));
    cin >> n >> m;
    for (i = 0; i < m; i++)
        cin >> relations[i].indexA >> relations[i].indexB >> relations[i].angry;
    for (i = 0; i < n; i++)
        fa[i] = i;
    sort(relations, relations + m, cmp);
    for (i = 0; i < m; i++)
    {
        int prisonA, prisonB;
        prisonA = find(relations[i].indexA);
        prisonB = find(relations[i].indexB);
        if (prisonA == prisonB)
        {
            cout << relations[i].angry;
            return 0;
        }

        if (!enemy[relations[i].indexA])
            enemy[relations[i].indexA] = relations[i].indexB;
        else
            fa[find(enemy[relations[i].indexA])] = find(relations[i].indexB);

        if (!enemy[relations[i].indexB])
            enemy[relations[i].indexB] = relations[i].indexA;
        else
            fa[find(enemy[relations[i].indexB])] = find(relations[i].indexA);
    }
    cout << "0";
    return 0;
}