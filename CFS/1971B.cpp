#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define debug(x) cout<<(x)<<endl
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORk(i, a, b, k) for (int i = (a); i <= (b); i += (k))
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define RFORK(i, a, b, k) for (int i = (a); i >= (b); i -= (k))

void solve()
{
  string s; cin >> s;

  if (all_of(s.begin(), s.end(), [&](char c){ return c == s[0]; }))
  {
    cout << "NO" << endl;
    return;
  }

  string r = s;
  sort(r.begin(), r.end());

  if (r != s)
  {
    cout << "YES" << endl << r << endl;
  }
  else
  {
    if (next_permutation(r.begin(), r.end()))
      cout << "YES" << endl << r << endl;
    else
      cout << "NO" << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t; cin >> t;
  while (t--) solve();
}