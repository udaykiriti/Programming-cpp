#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve()
{
  int n; cin >> n;
  unordered_map<char, int> freq;
  for (int i = 0; i < n; i++)
  {
    string s; cin >> s;
    for (char c : s)
      freq[c]++;
  }

  bool possible = true;
  for (const auto &p : freq)
  {
    if (p.second % n != 0)
    {
      possible = false;
      break;
    }
  }

  if (possible)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(0);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}