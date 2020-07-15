#include <bits/stdc++.h>
using namespace std;
const int maxN = 100100;
const int mod = 10000;
string s;
long long op1[maxN];
char op2[maxN];
int num1, num2;
void handle()
{
    switch (op2[num2])
    {
    case '+':
        op1[num1 - 1] = (op1[num1 - 1] + op1[num1]) % mod;
        num1--;
        break;
    case '-':
        op1[num1 - 1] = (op1[num1 - 1] - op1[num1]) % mod;
        num1--;
        break;
    case '*':
        op1[num1 - 1] = (op1[num1 - 1] * op1[num1]) % mod;
        num1--;
        break;
    case '/':
        op1[num1 - 1] = (op1[num1 - 1] / op1[num1]) % mod;
        num1--;
        break;
    }
}
void work1()
{
    while (num2 > 0 && op2[num2] != '(')
    {
        handle();
        num2--;
    }
}

void work2()
{
    while (num2 > 0 && (op2[num2] == '*' || op2[num2] == '/'))
    {
        handle();
        num2--;
    }
}

int main()
{
    cin >> s;
    int len = s.length();
    int i = 0;
    while (i < len)
    {
        if (s[i] <= '9' && s[i] > '0')
        {
            long long temp = 0;
            while (i < len && s[i] >= '0' && s[i] <= '9')
            {
                temp = (temp * 10 + s[i] - '0') % mod;
                i++;
            }
            num1++;
            op1[num1] = temp;
        }
        if (i == len)
            break;
        switch (s[i])
        {
        case '+':
        case '-':
            work1();
            op2[++num2] = s[i];
            break;
        case '*':
        case '/':
            work2();
            op2[++num2] = s[i];
            break;
        case '(':
            op2[++num2] = s[i];
            break;
        case ')':
            work1();
            num2--;
            break;
        }
        ++i;
        cout << num1 << endl;
        for (int i = 1; i <= num1; ++i)
            cout << op1[i] << " ";
        cout << endl;
        cout << num2 << endl;
        for (int i = 1; i <= num2; ++i)
            cout << op2[i] << " ";
        cout << endl
             << endl;
    }
    work1();
    cout << op1[1] << endl;
    return 0;
}