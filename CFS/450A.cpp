#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define Vellipoo return 0

void solve()
{
  int n, m; cin >> n >> m;
  vector<int> a(n);
  FOR(i, 0, n)
    cin >> a[i];
  queue<pair<int, int>> q;
  FOR(i, 0, n)
  q.push({i, a[i]});
  int lastChild = -1;
  while (!q.empty())
  {
    auto child = q.front();
    q.pop();
    child.second -= m;
    if (child.second > 0)
      q.push(child);
    else
      lastChild = child.first + 1;
  }
  cout << lastChild << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int t = 1;
  // Uncomment the next line if there are multiple test cases
  // cin >> t;
  while (t--) solve();
  Vellipoo;
}