#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define flushOut cout.flush()
#define input(x) cin >> x
#define print(x) cout << x << endl
#define checkExit(resp) \
  if (resp == "-1")     \
  return
#define FOR(i, start, end) for (int i = (start); i < (end); ++i)
#define GG return 0;

void solve()
{
  ll n;
  input(n);

  string resp;

  print("mul 9");
  flushOut;
  input(resp);
  checkExit(resp);

  print("digit");
  flushOut;
  input(resp);
  checkExit(resp);

  print("digit");
  flushOut;
  input(resp);
  checkExit(resp);

  print("add " << (n - 9));
  flushOut;
  input(resp);
  checkExit(resp);

  print("!");
  flushOut;
  input(resp);
  checkExit(resp);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  input(t);
  FOR(i, 0, t)
  {
    solve();
  }
  GG
}
