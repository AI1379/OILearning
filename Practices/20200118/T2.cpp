#include <bits/stdc++.h>
using namespace std;
map<char, int> sheet;
stack<int> stk;
string s;
int len;
int main()
{
    int i, tmp, x, y;
    cin >> s;
    len = s.length();
    i = 0;
    while (cin >> tmp)
    {
        sheet[(char)('A' + i)] = tmp;
        i++;
    }
    for (i = 0; i < len; i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            stk.push(sheet[s[i]]);
        }
        else
        {
            x = stk.top();
            stk.pop();
            y = stk.top();
            stk.pop();
            switch (s[i])
            {
            case '+':
                stk.push(x + y);
                break;

            case '-':
                stk.push(y - x);
                break;

            case '*':
                stk.push(x * y);
                break;

            case '/':
                stk.push(y / x);
                break;

            default:
                break;
            }
        }
    }
    cout<<stk.top();
    system("pause");
    return 0;
}