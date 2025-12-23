#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(NULL);
  string s; cin >> s;
  int len = s.length();
  for (int i = 0; i < len; ++i)
  {
    int d1 = s[i] - '0';
    if (d1 % 8 == 0)
    {
      cout << "YES\n" << d1 << '\n';
      return 0;
    }
  }

  for (int i = 0; i < len; ++i)
  {
    for (int j = i + 1; j < len; ++j)
    {
      int d1 = s[i] - '0';
      int d2 = s[j] - '0';
      int num = d1 * 10 + d2;
      if (num % 8 == 0)
      {
        cout << "YES\n" << num << '\n';
        return 0;
      }
    }
  }

  for (int i = 0; i < len; ++i)
  {
    for (int j = i + 1; j < len; ++j)
    {
      for (int k = j + 1; k < len; ++k)
      {
        int d1 = s[i] - '0';
        int d2 = s[j] - '0';
        int d3 = s[k] - '0';
        int num = d1 * 100 + d2 * 10 + d3;
        if (num % 8 == 0)
        {
          cout << "YES\n"<< num << '\n';
          return 0;
        }
      }
    }
  }

  cout << "NO\n";
  return 0;
}