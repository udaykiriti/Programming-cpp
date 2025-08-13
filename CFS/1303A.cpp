#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)

int main()
{
  int t; cin >> t;
  while (t--)
  {
    int c = 0, pos = 0, pos2 = 0;
    string s, a;  cin >> s;
    FOR(i, 0, s.length())
    {
      if (s[i] == '1')
      {
        pos = i;
        break;
      }
    }

    RFOR(i, s.length() - 1, pos)
    {
      if (s[i] == '1')
      {
        pos2 = i;
        break;
      }
    }

    FOR(i, pos, pos2)
    {
      if (s[i] == '0') c++;
      else a += '1';
    }
    cout << c << endl;
  }
  return 0;
}