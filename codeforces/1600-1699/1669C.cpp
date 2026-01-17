#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define debug(x) cout << #x << " = " << x << endl;
#define debugVec(v)    \
  cout << #v << " = "; \
  for (auto u : v)     \
    cout << u << " ";  \
  cout << endl;

#define ll long long
#define vi vector<int>
#define EXIT return 0
int n;
vi a;
bool solveParity(int start)
{
  bool isEven = (a[start] % 2 == 0);
  for (int i = start + 2; i < n; i += 2)
    if ((a[i] % 2 == 0) != isEven)
      return false;
  return true;
}

void solve()
{
  cin >> n; a.resize(n);
  FOR(i, 0, n) cin >> a[i];
  if (solveParity(0) && solveParity(1)) cout << "YES" << endl;
  else cout << "NO" << endl;
}

int main()
{
  fast;
  int t; cin >> t;
  while (t--) solve();
  EXIT;
}