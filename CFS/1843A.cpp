#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define ln "\n"
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define GG return 0
#define PRINT(x) cout << x << ln
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define SORT(v) sort((v).begin(), (v).end())

void solve()
{
  int n; cin >> n;
  vector<int> a(n);
  FOR(p, 0, n) cin >> a[p];

  SORT(a);
  int cnt = 0;
  FOR(p, 0, (n + 1) / 2)
    cnt += a[n - 1 - p] - a[p];
  PRINT(cnt);
}

int main()
{
  stop_sync; untie_ios;
  int t; cin>>t;
  while(t--) solve();
  GG;
}