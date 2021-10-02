#include <bits/stdc++.h>
using namespace std;
string str;
int p, k, s;
int next[210];
vector<string> dic;
bool kmp(string t, string p)
{
    memset(next, 0, sizeof(next));
    next[0] = -1;
    int i = 0, j = -1;
    while (i < strlen(p))
    {
        if (j == -1 || p[i] == p[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
    i = 0;
    j = 0;
    while (i < t.length() && j < p.length())
    {
        if (j == -1 || t[i] == p[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    return j == p.length;
}
int main()
{
    int i;
    cin >> p >> k;
    while (p--)
    {
        string in;
        cin >> in;
        str += in;
    }
    cin >> s;
    while (s--)
    {
        string column;
        cin >> column;
        dic.push_back(column);
    }
}