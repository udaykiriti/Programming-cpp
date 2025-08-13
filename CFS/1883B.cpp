#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i <= (b); i += (k))
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= (k))

void solve()
{
  const int B = 26;
  long n, k; cin >> n >> k;
  string s; cin >> s;
  int v[B] = {0};
  FOR(p, 0, s.size() - 1)
    ++v[s[p] - 'a'];
  long cnt = 0;
  FOR(p, 0, B - 1)
    cnt += v[p] % 2;
  cout << (cnt <= k + 1 ? "YES" : "NO") << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t ; cin >> t;
  while (t--) solve();
  return 0;
}