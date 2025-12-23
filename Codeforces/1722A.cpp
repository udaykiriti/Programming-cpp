#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  int t; cin >> t;
  while (t--)
  {
    int n; string s; cin >> n >> s;
    if (n != 5)
    {
      cout << "NO\n";
      continue;
    }
    string target = "Timur";
    sort(s.begin(), s.end());
    sort(target.begin(), target.end());

    if (s == target) cout << "YES\n";
    else cout << "NO\n";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  solve();
  return 0;
}