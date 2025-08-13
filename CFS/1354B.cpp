/*
    Codeforces Problem 1354B - Ternary String
    Problem Link: https://codeforces.com/problemset/problem/1354/B

    Given a string consisting of only characters '1', '2', and '3',
    find the length of the smallest substring that contains at least
    one occurrence of each of the three characters.

    If no such substring exists, output 0.
*/

#include <bits/stdc++.h>
#include <stdio.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

// Macros
#define ll long long
#define scl(n) scanf("%lld", &n)
#define scll(n, m) scanf("%lld%lld", &n, &m)
#define scc(c) scanf("%c", &c)
#define fr(i, n) for (ll i = 0; i < n; i++) // Use this macro for loops
#define fr1(i, n) for (ll i = 1; i <= n; i++)
#define pfl(x) printf("%lld\n", x)
#define pb push_back
#define debug cout << "I am here" << endl
#define pno cout << "NO" << endl
#define pys cout << "YES" << endl
#define tcas(i, t) for (ll i = 1; i <= t; i++)

#define l(s) s.size()
#define asort(a) sort(a, a + n)
#define all(x) (x).begin(), (x).end()
#define dsort(a) sort(a, a + n, greater<int>())
#define vasort(v) sort(v.begin(), v.end())
#define vdsort(v) sort(v.begin(), v.end(), greater<int>())
#define uniquee(x) x.erase(unique(x.begin(), x.end()), x.end())
#define pn printf("\n")
#define el cout << endl
#define md 1000000007
#define inf 9e18
#define ps cout << " "
#define Pai acos(-1.0)
#define pr pair<ll, ll>
#define ff first
#define ss second
#define mem(a, i) memset(a, i, sizeof(a))
#define pcas(i) cout << "Case " << i << ": " << endl
#define FastIO                  \
  ios_base::sync_with_stdio(0); \
  cin.tie(NULL);                \
  cout.tie(NULL)

void solve()
{
  string s; cin >> s;
  ll n = l(s);
  ll ans = inf;

  // To keep track of the last positions of '1', '2', and '3'
  vector<ll> last_pos(4, -1); // 1-based indexing for '1', '2', '3'

  fr(i, n)
  {                           // Use fr(i, n) for loop
    last_pos[s[i] - '0'] = i; // Store the last occurrence of the character

    // If all three characters have appeared, calculate the possible substring
    if (last_pos[1] != -1 && last_pos[2] != -1 && last_pos[3] != -1)
    {
      ll mn = min({last_pos[1], last_pos[2], last_pos[3]});
      ll mx = max({last_pos[1], last_pos[2], last_pos[3]});
      ans = min(ans, mx - mn + 1); // Find the minimum length substring
    }
  }

  if (ans == inf)
    cout << 0 << endl; // No valid substring found
  else
    cout << ans << endl; // Output the smallest valid substring length
}

int main()
{
  FastIO;
  ll t; cin >> t;
  tcas(cs, t) solve(); // Call solve function for each test case
  return 0;
}

/// **************************Before submit****************************
/// * Check for edge cases like n = 1, all characters same
/// * Ensure "YES"/"NO" output format if needed
/// * Watch for integer overflows and array bounds
