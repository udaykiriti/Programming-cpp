#include <bits/stdc++.h>
using namespace std;

#define FASTIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define TESTCASES() \
  int t;            \
  cin >> t;         \
  while (t--)
#define READSTR(s) \
  string s;        \
  cin >> s
#define LASTCHAR(s) s[s.length() - 1]
#define PRINT_RESULT(res) cout << (res) << '\n'
#define IS_GREATER(n1, n2) ((n1) > (n2))
#define IS_SMALLER(n1, n2) ((n1) < (n2))

int main()
{
  FASTIO();
  TESTCASES()
  {
    READSTR(s1);
    READSTR(s2);

    int len1 = s1.length();
    int len2 = s2.length();

    char c1 = LASTCHAR(s1);
    char c2 = LASTCHAR(s2);

    bool result = IS_GREATER(len1, len2);

    if (s1 == s2)
    {
      PRINT_RESULT("=");
      continue;
    }
    else if (c1 == c2 && c1 == 'S')
    {
      result = !result;
    }
    else if (c1 != c2)
    {
      result = IS_SMALLER(c1, c2);
    }

    PRINT_RESULT(result ? ">" : "<");
  }
  return 0;
}
