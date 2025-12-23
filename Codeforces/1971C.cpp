#include <bits/stdc++.h>
using namespace std;
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define ln "\n"
#define pb push_back
#define sz(x) int((x).size())
#define All(x) (x).begin(), (x).end()
using i64 = long long;
#define BYE return 0;

void solve()
{
  i64 a, b, c, d; cin >> a >> b >> c >> d;
  if (a > b)
    swap(a, b);
  bool u = (a <= c && c <= b);
  bool v = (a <= d && d <= b);
  cout << (u ^ v ? "YES" : "NO") << ln;
}

int main()
{
  stop_sync; untie_ios;
  int t; cin>>t;
  while(t--) solve();
  return 0;
}