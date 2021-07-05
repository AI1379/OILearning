#include <bits/stdc++.h>
using namespace std;
struct node
{
    int left, right;
    int value;
};
vector<node> tree;
int n;
node makeNode(int l, int r, int v)
{
    node tmp;
    tmp.left = l, tmp.right = r, tmp.value = v;
    return tmp;
}
int main()
{
    int i, x, y;
    cin >> n;
    tree.push_back(makeNode(-1, -1, -1));
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        tree.push_back(makeNode(x, -1, -1));
    }
    for (i = 1; i <= n; i++)
    {
        cin >> x >> y;
        tree[i].left = x, tree[i].right = y;
    }
    
}