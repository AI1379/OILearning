//TODO: 表达式求值 https://dev.xjoi.net/contest/1426/problem/2

#include <bits/stdc++.h>
using namespace std;
stack<char> stkOpt;
stack<long long> stkNum;
int priority[256];
int compute(int x, int y, char opt)
{
    switch (opt)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        return -1;
    }
}
string preMake(string str)
{
    int len = str.length(), i;
    string res;
    bool flag;
#ifdef DEBUG
    cout << len << endl;
#endif
    flag = false;
    for (i = 0; i < len; i++)
    {
        if (str[i] != '+' && str[i] != '-')
            res.push_back(str[i]);
        else
        {
            if (i == 0)
            {
                res.push_back('(');
                res.push_back('0');
                flag = true;
            }
            else if ((str[i - 1] < '0' || str[i - 1] > '9') && str[i - 1] != ')')
            {
                res.push_back('(');
                res.push_back('0');
                flag = true;
            }
            res.push_back(str[i]);
#ifdef DEBUG
            cout << res << endl;
#endif
        }
        if (((int)('0') <= (int)(str[i]) && (int)(str[i]) <= (int)('9')) && flag)
        {
            res.push_back(')');
            flag = false;
        }
    }
    return res;
}
int main()
{
    string input;
    long long optNum1, optNum2, tmpNum = 0;
    int len, i;
    char tmpChar;
    priority[(int)('*')] = 2;
    priority[(int)('+')] = 2;
    cin >> input;
    input = preMake(input);
#ifdef DEBUG
    cout << input << endl;
#endif
    len = input.length();
    for (i = 0; i < len; i++)
    {
        if ((int)('0') <= (int)(input[i]) && (int)(input[i]) <= (int)('9'))
        {
            tmpNum = 0;
            for (; i < len && (int)('0') <= (int)(input[i]) && (int)(input[i]) <= (int)('9'); i++)
            {
                tmpNum = tmpNum + (int)(input[i]) - (int)('0');
                if (!((int)('0') <= (int)(input[i + 1]) && (int)(input[i + 1]) <= (int)('9')))
                    break;
            }
            stkNum.push(tmpNum);
            if (i == len)
                break;
        }
        else
        {
            if (input[i] != '(' && input[i] != ')')
            {
                if (stkOpt.empty())
                {
                    stkOpt.push(input[i]);
                }
                else if (priority[(int)(input[i])] >= priority[(int)(stkOpt.top())])
                {
                    stkOpt.push(input[i]);
                }
                else
                {
                    while (priority[(int)(input[i])] < priority[(int)(stkOpt.top())])
                    {
                        tmpNum = stkNum.top();
                        stkNum.pop();
                        if (stkNum.empty())
                            break;
                        tmpNum = compute(stkNum.top(), tmpNum, stkOpt.top());
                        stkNum.pop();
                        stkNum.push(tmpNum);
                        stkOpt.pop();
                        if (stkOpt.empty())
                            break;
                    }
                }
            }
            else if (input[i] == '(')
            {
                stkOpt.push(input[i]);
            }
            else
            {
                while (stkOpt.top() != '(')
                {
                    tmpNum = stkNum.top();
                    stkNum.pop();
                    tmpNum = compute(stkNum.top(), tmpNum, stkOpt.top());
                    stkNum.pop();
                    stkNum.push(tmpNum);
                    stkOpt.pop();
                }
                stkOpt.pop();
            }
        }
    }
    /*
#ifdef DEBUG
    while (!stkNum.empty())
    {
        cout << stkNum.top() << endl;
        stkNum.pop();
    }
    while (!stkOpt.empty())
    {
        cout << stkOpt.top() << endl;
        stkOpt.pop();
    }
    cout << endl;
#endif
*/
    while (!stkOpt.empty())
    {
        tmpNum = stkNum.top();
        stkNum.pop();
        tmpNum = compute(stkNum.top(), tmpNum, stkOpt.top());
        stkNum.pop();
        stkOpt.pop();
        stkNum.push(tmpNum);
    }
#ifdef DEBUG
    while (!stkNum.empty())
    {
        cout << stkNum.top() << endl;
        stkNum.pop();
    }
    while (!stkOpt.empty())
    {
        cout << stkOpt.top() << endl;
        stkOpt.pop();
    }
#else
    cout << stkNum.top();
#endif
    return 0;
}

//(1*(2*(3+4)*5*6))+7
//-3*(+5-7*2)-(0)
//20+(7-7)*(-6)+(-9)