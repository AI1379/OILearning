#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
int tree[200005], pos[100005], n, size = 0;
int main()
{
    int i;
    memset(tree, -1, sizeof(tree));
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> tree[i];
        if (tree[i] != -1)
        {
            size++;
            pos[tree[i]] = i;
        }
    }
    printf("The size of the tree is %d\n", size);
    printf("Node %d is the root node of the tree\n", tree[1]);
    for (i = 1; i <= size; i++)
    {
        printf("The father of node %d is %d, the left child is %d, and the right child is %d\n",
               i, tree[pos[i] / 2], tree[pos[i] * 2], tree[pos[i] * 2 + 1]);
    }
    return 0;
}