#include <bits/stdc++.h>
using namespace std;
int a, b;
int pos[100000];
int diff[100000];
int main()
{
    int i, j;
    cin >> a >> b;
    for (i = 0; i < a; i++)
        cin >> pos[i];
    sort(pos, pos + a);
    for (i = 1; i < a; i++)
        diff[i] = pos[i] - pos[i - 1];
}