#include <bits/stdc++.h>
using namespace std;

#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define ln "\n"
#define pb push_back
#define sz(x) int((x).size())
#define All(x) (x).begin(), (x).end()
#define multicase \
  int t;          \
  cin >> t;       \
  while (t--)
#define GG return 0;
#define PRINT(x) cout << x << ln
#define LOOP(i, a, b) for (int i = (a); i < (b); i++)

using i64 = long long;

void solve()
{
  i64 n;
  cin >> n;
  string s;
  cin >> s;

  i64 cnt = 0, idx = 0;

  while (idx != string::npos)
  {
    idx = s.find("mapie", idx);
    if (idx == string::npos)
      break;
    ++cnt;
    s[idx + 2] = '$';
    ++idx;
  }

  idx = 0;
  while (idx != string::npos)
  {
    idx = s.find("map", idx);
    if (idx == string::npos)
      break;
    ++cnt;
    s[++idx] = '$';
  }

  idx = 0;
  while (idx != string::npos)
  {
    idx = s.find("pie", idx);
    if (idx == string::npos)
      break;
    ++cnt;
    s[++idx] = '$';
    ++idx;
  }

  PRINT(cnt);
}

int main()
{
  stop_sync;
  untie_ios;
  multicase
  {
    solve();
  }
  GG;
}