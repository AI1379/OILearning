#include <stack>
#include <iostream>

using namespace std;

string bracketLeft = "{[(";
string bracketRight = "}])";

bool BracketCheck(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char chr = str[i];
        int indexLeft = -1, indexRight = -1;
        indexLeft = bracketLeft.find(chr);
        indexRight = bracketRight.find(chr);
        if (indexLeft >= 0)
            s.push(chr);
        else if (indexRight >= 0)
        {
            if (!s.empty() && s.top() == bracketLeft[indexRight])
                s.pop();
            else
                return false;
        }
    }
    return s.empty();
}
int main()
{
    string s;
    cin >> s;
    if (BracketCheck(s))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}