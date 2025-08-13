#include <bits/stdc++.h>
using namespace std;
#define input(x) cin >> x
#define output(x) cout << x << '\n'
#define FAST_IO()                   \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);

void solve()
{
  int n; input(n);
  string s;input(s);
  string ans;
  for (int i = n - 1; i >= 0;)
  {
    if (s[i] == '0')
    {
      int num = stoi(s.substr(i - 2, 2));
      ans += char(96 + num);
      i -= 3;
    }
    else
    {
      ans += char(96 + (s[i] - '0'));
      i--;
    }
  }
  reverse(ans.begin(), ans.end());
  output(ans);
}

int main()
{
  FAST_IO();
  int t; input(t);
  while (t--) solve();
  return 0;
}