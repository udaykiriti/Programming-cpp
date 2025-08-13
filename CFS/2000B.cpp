#include <bits/stdc++.h>
using namespace std;
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define ln "\n"
#define pb push_back
#define sz(x) int((x).size())
#define All(x) (x).begin(), (x).end()
using i64 = long long;
#define EXIT return 0

void solve()
{
  i64 n, x; cin >> n >> x;
  i64 left = x - 1, right = x + 1;
  bool rule = true;

  for (i64 p = 1; p < n; p++)
  {
    cin >> x;
    if (x == left)
      --left;
    else if (x == right)
      ++right;
    else
      rule = false;
  }
  cout << (rule ? "YES" : "NO") << ln;
}

int main()
{
  stop_sync; untie_ios;
  int t; cin>>t;
  while(t--) solve();
  EXIT;
}