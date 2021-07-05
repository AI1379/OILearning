#include <bits/stdc++.h>
using namespace std;
int lis1[110], lis2[110], h[110];
int n;
int main()
{
  int i, j, ans = 0;
  cin >> n;
  for (i = 1; i <= n; i++)
    cin >> h[i];
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j < i; j++)
    {
      if (h[j] < h[i])
      {
        lis1[i] = max(lis1[i], lis1[j]);
      }
    }
    lis1[i]++;
  }
  for (i = n; i >= 1; i--)
  {
    for (j = n; j > i; j--)
    {
      if (h[j] < h[i])
      {
        lis2[i] = max(lis2[i], lis2[j]);
      }
    }
    lis2[i]++;
  }
  for (i = 1; i <= n; i++)
  {
    ans = max(ans, lis1[i] + lis2[i] - 1);
  }
  cout << n - ans;
  return 0;
}
