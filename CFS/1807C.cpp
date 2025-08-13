#include <bits/stdc++.h>
using namespace std;
#define FastIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(nullptr);                 \
  cout.tie(nullptr);
#define int long long
#define endl "\n"
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i = 0; i < n; i++)

bool visited(const vector<pair<char, char>> &ans, char ch)
{
  for (auto &p : ans)
  {
    if (p.first == ch)
      return true;
  }
  return false;
}

bool checkPos(const vector<pair<char, char>> &ans, char ch, char parity)
{
  for (auto &p : ans)
  {
    if (p.first == ch && p.second == parity)
      return true;
  }
  return false;
}

void solve()
{
  int n; cin >> n;
  string s; cin >> s;
  vector<pair<char, char>> ans;
  bool sol = true;

  FOR(i, 0, n)
  {
    char parity = (i % 2 == 0) ? 'o' : 'e';
    if (!visited(ans, s[i]))
      ans.pb({s[i], parity});
    if (!checkPos(ans, s[i], parity))
    {
      sol = false;
      break;
    }
  }
  cout << (sol ? "YES" : "NO") << endl;
}

int32_t main()
{
  FastIO;
  int t; cin >> t;
  while (t--) solve();
  return 0;
}