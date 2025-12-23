#include <bits/stdc++.h>
using namespace std;
#define MAX 1e6 + 10
#define MOD 1000000007
#define PI acos(-1)
#define R 510
#define makefast__                  \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
using ll = long long int;
using dl = double;
using ld = long double;
using ull = unsigned long long;
const long N = 3e5 + 10;
const long maxn = 5e5 + 10;
ll aarray[N];
ll magic[R][R];
vector<ll> primes;
bool check[1000001];
ll large[10000005];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
ll vis[N];
map<ll, ll> mp;
void solve()
{
  ll i, j, k, m, n, l, r, q, p, ans, sum = 0;
  string str;
  bool yes = true;
  vector<ll> v;
  ll x, y;
  cin >> n >> m >> x >> y;
  if (x == 1 && y == 1)
  {
    cout << 1 << " " << m << " " << n << " " << " " << 1 << "\n";
    return;
  }
  if (x == 1 && y == m)
  {
    cout << 1 << " " << 1 << " " << n << " " << 1 << "\n";
    return;
  }
  if (x == n && y == 1)
  {
    cout << 1 << " " << 1 << " " << n << " " << m << "\n";
    return;
  }
  if (x == n && y == m)
  {
    cout << 1 << " " << m << " " << n << " " << 1 << "\n";
    return;
  }
  ll dis = m - y;
  ll dis2 = abs(1 - y);
  if (dis > dis2)
  {
    cout << 1 << " " << m << " " << n << " " << 1 << "\n";
    return;
  }
  else
  {
    cout << 1 << " " << 1 << " " << n << " " << m << "\n";
    return;
  }
}
int main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // tle khaite chas to endl use kor
  makefast__
      string str;
  ll i, j, n, m, k, t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}