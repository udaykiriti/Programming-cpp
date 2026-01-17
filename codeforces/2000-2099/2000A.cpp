#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i <= (b); i += (k))
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= (k))

unordered_set<int> important;

void precompute()
{
  FOR(x, 2, 99)
  {
    string s = "10" + to_string(x);
    important.insert(stoi(s));
  }
}

void solve()
{
  int a; cin >> a;
  cout << (important.count(a) ? "YES" : "NO") << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); 
  precompute();
  int t; cin >> t;
  while (t--) solve();
  return 0;
}