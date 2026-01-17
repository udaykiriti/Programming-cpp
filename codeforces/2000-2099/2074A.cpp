#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using i64 = long long int;
using vi = vector<int>;
using vii = vector<i64>;
template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using pq_ = priority_queue<T, vector<T>, greater<T>>;
template <typename T1, typename T2>
using vp = vector<pair<T1, T2>>;

template <typename key, typename val = null_type, typename cmp = less<key>>
using pbds = tree<key, val, cmp, rb_tree_tag, tree_order_statistics_node_update>;

#define ln "\n"
#define stop_sync ios::sync_with_stdio(false)
#define untie_ios cin.tie(nullptr)
#define pb push_back
#define mp make_pair
#define sz(x) int((x).size())
#define All(x) (x).begin(), (x).end()
#define scanv(x)    \
  for (auto &i : x) \
  cin >> i
#define minE(a) (*min_element(All(a)))
#define maxE(a) (*max_element(All(a)))
#define FIXED(x) cout << fixed << setprecision(x)
#define bug(x) cout << (#x) << ": " << (x) << ln
#define EXIT return 0

const long double PI = acos(-1.0L);
struct
{
  const int i = (1e9) + 7;
  const i64 l = (i64)(1e9) + 7ll;
} MOD;

i64 binpow(i64 a, i64 b, i64 m)
{
  a %= m;
  i64 ans = 1ll;
  while (b > 0)
  {
    if (b & 1) ans = ans * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return ans;
}

void solve()
{
  int l, r, d, u; cin >> l >> r >> d >> u;
  if (l == r && r == d && d == u && l == u)
    cout << "Yes" << ln;
  else
    cout << "No" << ln;
}

int main(void)
{
  stop_sync; untie_ios;
  int t; cin >> t;
  while (t--) solve();
  EXIT;
}