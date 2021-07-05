#include <bits/stdc++.h>
using namespace std;
unsigned long long k, n;
int main()
{
    cin >> n >> k;
    k ^= k >> 1;
    while (n--)
        cout << (k >> n & 1);
    return 0;
}