#include <bits/stdc++.h>
#define FastIO()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define vb vector<bool>
#define vbb vector<vector<bool>>
#define vl vector<long long>
#define vll vector<vector<long long>>
#define vc vector<char>
#define vcc vector<vector<char>>
#define vp vector<pair<int, int>>
#define vpp vector<vector<pair<int, int>>>
#define vs vector<string>
#define si set<int>
#define pb push_back
#define vt(v, n, m, int) vector<vector<int>> v(n, vector<int>(m));
#define vti(v, n, m, int, initial) vector<vector<int>> v(n, vector<int>(m, initial));
#define pi pair<int, int>
#define pl pair<ll, ll>
#define sz(s) s.size()
#define PI 3.14159265359
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define input(n)    \
  for (auto &i : n) \
    cin >> i;
#define loop(from, to) for (int i = from; i < to; i++)
#define loopr(from, to) for (int i = from; i >= to; --i)
#define loop2(from2, to2) for (int j = from2; j < to2; j++)
#define loop3(from3, to3) for (int k = from3; k < to3; k++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define is(x) cout << ((x) ? "YES\n" : "NO\n");
#define point(x) cout << fixed << setprecision(x);
#define endd '\n'
#define SEEYAH return
#define BYE return 0
using namespace std;
vp directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
void solve()
{
  ll a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
  int s = 0;
  vp v = {{a1, b1}, {a2, b2}, {a1, b2}, {a2, b1}, {a2, b1}, {a1, b2}, {a2, b2}, {a1, b1}};

  for (int i = 0; i < sz(v); i += 2)
  {
    ll c = 0, cc = 0;
    if (v[i].first > v[i].second)
      c++;
    else if (v[i].first < v[i].second)
      cc++;

    if (v[i + 1].first > v[i + 1].second)
      c++;
    else if (v[i + 1].first < v[i + 1].second)
      cc++;

    if (c > cc)
      s++;
  }
  cout << s << endd;
  SEEYAH;
}
int main()
{
  FastIO();
  ll t = 1;cin >> t;
  while (t--) solve();
  BYE;
}